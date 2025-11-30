#include "analysis.hpp"
int main(int argc,char**argv){
    try{
        if(argc!=6)throw std::invalid_argument("usage: planner_cli MAP START_ROW START_COL GOAL_ROW GOAL_COL");
        auto grid=read_grid(argv[1]);Point start={std::stoi(argv[2]),std::stoi(argv[3])},goal={std::stoi(argv[4]),std::stoi(argv[5])};
        auto route=path(grid,start,goal);
        if(route.empty()){std::cout<<"unreachable\n";return 1;}
        if(!valid_path(grid,route,start,goal))throw std::runtime_error("invalid planner result");
        std::cout<<"row,col\n";for(auto[r,c]:route)std::cout<<r<<","<<c<<"\n";
    }catch(const std::exception&e){std::cerr<<e.what()<<"\n";return 2;}
}
