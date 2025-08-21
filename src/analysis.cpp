#include "analysis.hpp"
#include <fstream>
Grid read_grid(const std::string&filename){
    std::ifstream input(filename);if(!input)throw std::runtime_error("cannot open map: "+filename);
    Grid grid;std::string line;
    while(std::getline(input,line)){
        if(!line.empty()&&line.back()=='\r')line.pop_back();
        grid.push_back(line);
    }
    if(grid.empty()||grid[0].empty())throw std::invalid_argument("empty map");
    for(const auto&row:grid){
        if(row.size()!=grid[0].size())throw std::invalid_argument("ragged map");
        for(char c:row)if(c!='.'&&c!='#')throw std::invalid_argument("maps use . and # only");
    }
    return grid;
}
bool valid_path(const Grid&grid,const std::vector<Point>&route,Point start,Point goal){
    if(route.empty()||route.front()!=start||route.back()!=goal)return false;
    for(std::size_t i=0;i<route.size();++i){
        auto [r,c]=route[i];
        if(r<0||r>=int(grid.size())||c<0||c>=int(grid[r].size())||grid[r][c]=='#')return false;
        if(i&&std::abs(r-route[i-1].first)+std::abs(c-route[i-1].second)!=1)return false;
    }
    return true;
}
