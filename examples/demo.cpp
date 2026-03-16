#include "analysis.hpp"
int main(){Grid grid={".......",".###...","...#...","......."};
    for(auto[r,c]:path(grid,{0,0},{3,6}))grid[r][c]='*';
    for(auto&row:grid)std::cout<<row<<"\n";
}
