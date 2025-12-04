#include "analysis.hpp"
#include <random>
void need(bool b){if(!b)throw std::runtime_error("planner regression failed");}
int main(){
    std::mt19937 rng(7);
    for(int trial=0;trial<100;++trial){
        Grid grid(12,std::string(12,'.'));
        for(auto&row:grid)for(char&c:row)if(rng()%4==0)c='#';
        grid[0][0]=grid[11][11]='.';
        auto a=path(grid,{0,0},{11,11}),b=path(grid,{0,0},{11,11},false);
        need(a.size()==b.size());
        if(!a.empty())need(valid_path(grid,a,{0,0},{11,11}));
    }
    need(!valid_path({".."},{{0,0},{0,0}},{0,0},{0,0}));
    bool rejected=false;try{path({"..","."},{0,0},{0,1});}catch(const std::invalid_argument&){rejected=true;}need(rejected);
    std::cout<<"100 seeded grids agree with uniform-cost search; route invariants pass\n";
}
