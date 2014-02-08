#include <fstream>
#include <iostream>
int main()
{
	int arraySize, temp, j;
	std::ifstream f("../list.txt");
	
	f >> arraySize;
	int *values = new int[arraySize];
	
	for(int i=0; i<arraySize; i++)
	{
		f >> values[i];
	}
	f.close();

	std::cout << "Input array:\n";
	for(int i=0; i<arraySize; i++)
		std::cout << values[i] << ", ";
	std::cout << "\n\n";

	for(int i=1; i<arraySize; i++)
	{
		temp = values[i];
		j = i-1;
		while(values[j]>temp)
		{
			values[j+1] = values[j];
			j--;
		}
		values[j+1] = temp;
	}

	std::cout << "Sorted array:\n";
	for(int i=0; i<arraySize; i++)
		std::cout << values[i] << ", ";
	std::cout << '\n';

	delete values;

	return 0;
}
