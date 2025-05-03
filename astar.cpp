#include <algorithm>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
using Grid=std::vector<std::string>;
using Point=std::pair<int,int>;
std::vector<Point> path(const Grid& grid,Point start,Point goal,bool heuristic=true) {
    if(grid.empty()||grid[0].empty()) throw std::invalid_argument("empty grid");
    int h=grid.size(),w=grid[0].size();
    for(auto& row:grid) if(int(row.size())!=w) throw std::invalid_argument("ragged grid");
    auto valid=[&](Point p){return p.first>=0&&p.first<h&&p.second>=0&&p.second<w&&grid[p.first][p.second]!='#';};
    if(!valid(start)||!valid(goal)) throw std::invalid_argument("invalid endpoint");
    auto id=[&](Point p){return p.first*w+p.second;};
    auto estimate=[&](Point p){return heuristic?std::abs(p.first-goal.first)+std::abs(p.second-goal.second):0;};
    std::vector<int> distance(h*w,1000000000),parent(h*w,-1);
    using Entry=std::tuple<int,int,int,int>;
    std::priority_queue<Entry,std::vector<Entry>,std::greater<Entry>> frontier;
    distance[id(start)]=0;frontier.emplace(estimate(start),0,start.first,start.second);
    const std::vector<Point> moves={{1,0},{-1,0},{0,1},{0,-1}};
    while(!frontier.empty()) {
        auto [priority,cost,r,c]=frontier.top();frontier.pop();
        (void)priority;
        Point p={r,c}; if(cost!=distance[id(p)]) continue;
        if(p==goal) {
            std::vector<Point> result;
            for(int at=id(goal);at!=-1;at=parent[at]) result.emplace_back(at/w,at%w);
            std::reverse(result.begin(),result.end());return result;
        }
        for(auto [dr,dc]:moves) {
            Point q={r+dr,c+dc};
            if(valid(q)&&cost+1<distance[id(q)]) {
                distance[id(q)]=cost+1;parent[id(q)]=id(p);
                frontier.emplace(cost+1+estimate(q),cost+1,q.first,q.second);
            }
        }
    }
    return {};
}
void require(bool condition){if(!condition)throw std::runtime_error("self-test failed");}
int main(){
    Grid grid={".......",".###...","...#...","......."};
    auto result=path(grid,{0,0},{3,6});
    require(result.size()==path(grid,{0,0},{3,6},false).size());
    require(result.size()==10);
    require(path({".#."},{0,0},{0,2}).empty());
    require(path({"."},{0,0},{0,0}).size()==1);
    for(std::size_t i=1;i<result.size();++i)
        require(std::abs(result[i].first-result[i-1].first)+std::abs(result[i].second-result[i-1].second)==1);
    for(auto [r,c]:result)grid[r][c]='*';
    for(auto& row:grid)std::cout<<row<<'\n';
    std::cout<<"Self-tests passed\n";
}
