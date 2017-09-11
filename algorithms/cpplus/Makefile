HOST = $(shell uname -s | tr A-Z a-z)

ifeq ($(HOST), darwin)
CXX = g++-7
endif
ifneq (,$(findstring MSYS,$(HOST)))
EXT = .exe
endif

CXXFLAGS = -std=c++11

.PHONY: all 
Targets = BubbleSort InsertionSort SelectionSort MergeSort QuickSort HeapSort CountSort
all: $(Targets)

BubbleSort: BubbleSort.cpp Driver.o
InsertionSort: InsertionSort.cpp Driver.o
SelectionSort: SelectionSort.cpp Driver.o
MergeSort: MergeSort.cpp Driver.o
QuickSort: QuickSort.cpp Driver.o
HeapSort: HeapSort.cpp Driver.o
CountSort: CountSort.cpp Driver.o

Driver.o: Driver.cpp

.PHONY: clean
clean: 
	rm *.o
	rm $(Targets)
