CC = g++
OPTS = -O3 -Wall

all: insertionSort mergeSort

insertionSort: insertionSort.cpp
	${CC} ${OPTS} insertionSort.cpp -o insertionSort.out

runInsertionSort:
	./insertionSort.out

mergeSort: mergeSort.cpp
	${CC} ${OPTS} mergeSort.cpp -o mergeSort.out

runMergeSort:
	./mergeSort.out

clean:
	rm -rf *.out