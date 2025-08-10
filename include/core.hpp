#pragma once
#include <algorithm>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <string>
#include <tuple>
#include <vector>
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cmath>

using Grid=std::vector<std::string>;
using Point=std::pair<int,int>;
std::vector<Point> path(const Grid& grid,Point start,Point goal,bool heuristic=true);
