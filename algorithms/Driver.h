#pragma once

#include <vector>
#include <functional>

void runMethod(int argn, 
               char* argv[], 
               std::function<void(std::vector<int>&)> processor);
