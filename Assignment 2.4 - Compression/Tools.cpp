#include "Tools.h"

#include <iostream>

void PrintArray(const int* array, size_t size)
{
	std::cout << "{";
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] < 0)
		{
			std::cout << array[i] * -1 << ",";
		}
		else
		{
			std::cout << array[i] << ",";
		}
	}
	std::cout << "}";

	std::cout << "\n";
}
