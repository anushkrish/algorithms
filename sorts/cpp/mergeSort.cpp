#include <fstream>
#include <iostream>

// this function merges the two sorted sub-arrays into one sorted array
void mergeSubArrays(int *values, int start, int middle, int end, int *temp)
{
	int i=start, j=middle, k=start;
	
	while(i<middle && j<end)
	{
		while(values[i] < values[j] && i<middle)
		{
			temp[k] = values[i];
			k++;
			i++;
		}
		while(values[j] <= values[i] && j<end)
		{
			temp[k] = values[j];
			k++;
			j++;
		}
	}
	while(i<middle)
	{
		temp[k] = values[i];
		k++;
		i++;
	}
	while(j<end)
	{
		temp[k] = values[j];
		k++;
		j++;
	}
			
	for(k=start; k<end; k++)
		values[k] = temp[k];
}

void sortSubArray(int *values, int start, int end, int *temp)
{
	if(end-start>1)
	{
		int middle = (start+end)/2;
		// divide the problem into two sub-arrays and separately sort each of them
		sortSubArray(values, start, middle, temp);
		sortSubArray(values, middle, end, temp);
		// conquer the problem by combining the sorted sub-arrays into one sorted array
		mergeSubArrays(values, start, middle, end, temp);
	}
}

void mergeSort(int *values, int arraySize)
{
	int *temp = new int[arraySize]; // allocate memory for a temporary array that helps with merging
	sortSubArray(values, 0, arraySize, temp); // sort the array
	delete temp; // deallocate memory from temporary array
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

	// sort the array using merge sort
	mergeSort(values, arraySize);

	// display the sorted array
	std::cout << "Sorted array:\n";
	for(int i=0; i<arraySize; i++)
		std::cout << values[i] << ", ";
	std::cout << '\n';

	// deallocate memory
	delete values;

	return 0;
}
