HOST = $(shell uname -s | tr A-Z a-z)

ifeq ($(HOST), darwin)
CXX = g++-7
endif
ifneq (,$(findstring MSYS,$(HOST)))
EXT = .exe
endif

CXXFLAGS = -std=c++11

.PHONY: all 
Targets = bfs roads moon dijkstra
all: $(Targets)

bfs: bfs.cpp 
roads: roads.cpp
mmon: moon.cpp
dijkstra: dijkstra.cpp

.PHONY: clean
clean: 
	rm *.o
	rm $(Targets)
