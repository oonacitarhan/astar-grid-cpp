#include "analysis.hpp"
#include <chrono>
int main(){auto start=std::chrono::steady_clock::now();
Grid grid(100,std::string(100,'.'));auto result=path(grid,{0,0},{99,99});if(result.size()!=199)return 1;
auto elapsed=std::chrono::duration<double>(std::chrono::steady_clock::now()-start).count();
std::cout<<"seconds,"<<elapsed<<"\n";
}
