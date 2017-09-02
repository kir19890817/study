HOST = $(shell uname -s | tr A-Z a-z)

ifeq ($(HOST), darwin)
CXX = g++-7
endif

CXXFLAGS = -std=c++11

all: BubbleSort InsertionSort SelectionSort

BubbleSort: BubbleSort.cpp Driver.o
InsertionSort: InsertionSort.cpp Driver.o
SelectionSort: SelectionSort.cpp Driver.o

Driver.o: Driver.cpp

clean: 
	rm *.o
	rm BubbleSort InsertionSort SelectionSort
