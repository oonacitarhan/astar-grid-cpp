#include "core.hpp"
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
