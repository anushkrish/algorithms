#include <fstream>
#include <iostream>

void insertionSort(int *values, int arraySize)
{
	int temp, j;
	for(int i=1; i<arraySize; i++)
	{
		temp = values[i];
		
		for(j=i; values[j-1]>temp; j--)
			values[j] = values[j-1];
		
		values[j] = temp;
	}
}

int main()
{
	int arraySize;
	
	// read array from file
	std::ifstream f("../list.txt");	   // open the file containing the input data
	f >> arraySize;                    // read the number of elements in the array
	int *values = new int[arraySize];  // allocate memory for the array
	for(int i=0; i<arraySize; i++)
		f >> values[i];                // read array values from the file
	f.close();                         // close the file

	// display the input array
	std::cout << "Input array:\n";
	for(int i=0; i<arraySize; i++)
		std::cout << values[i] << ", ";
	std::cout << "\n\n";

	// sort the array using insertion sort
	insertionSort(values, arraySize);

	// display the sorted array
	std::cout << "Sorted array:\n";
	for(int i=0; i<arraySize; i++)
		std::cout << values[i] << ", ";
	std::cout << '\n';

	// deallocate memory
	delete values;

	return 0;
}
