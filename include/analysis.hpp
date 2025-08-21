#pragma once
#include "core.hpp"

Grid read_grid(const std::string& filename);
bool valid_path(const Grid&grid,const std::vector<Point>&route,Point start,Point goal);
