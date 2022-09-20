#include "Data.h"

#include <iostream>

// ToDo Add Template

// Compresses array
int* Deflate(const int* data, const size_t& k_size)
{
	int key = data[0];
	int quantity = 0;
	int counter = 1;
	int a = 0;
	int b = 1;

	// Counts the new size of array
	for (size_t i = 0; i < k_size; ++i)
	{
		if (data[i] != key)
		{
			counter++;
		}
	}

	key = data[0];

	int* zipped = new int[counter * 2];


	for (size_t i = 0; i < k_size; ++i)
	{
		if (data[i] == key)
		{
			quantity++;
		}
		else
		{
			// if the quantity is 1 we make the key negative to establish the size to 1... 
			if (quantity == 1)
			{
				key *= -1;
				zipped[a] = key;
				// add 1 because there is no quanitiy
				a++;
				b++;

				key = data[i];
				quantity = 1;
			}
			else
			{
				zipped[a] = key;
				zipped[b] = quantity;

				key = data[i];
				quantity = 1;

				a += 2;
				b += 2;
			}

		}
	}
	// if the last key has a quanity of 1 make it negative
	if (quantity == 1)
	{
		key *= -1;
		zipped[a] = key;
	}
	else
	{
		zipped[a] = key;
		zipped[b] = quantity;
	}
	

	return zipped;
}

// Decompresses array
int* Inflate(const int* data, const size_t& k_size)
{
	int key;
	int quantity = 0;
	int counter = 0;

	int mcounter = 0;
	// Counts the new size of array
	for (size_t i = 0; i < k_size; ++i)
	{
		// if the number is negative at 1 add 1 to mcounter
		if(data[i] < 0)
		{
			++mcounter;
		}
		// if the number is postive skip the key and add the quantity
		else
		{
			++i;
			mcounter += data[i];
		}
		
	}

	int* extracted = new int[mcounter];


	for (size_t i = 0; i < k_size; ++i)
	{
		key = data[i];

		// Prevents array out of bounds exception
		if (key >= 0)
		{
			quantity = data[i + 1];
		}

		// if the key is negative make it positive and add it to the array
		if (key < 0)
		{
			key *= -1;
			extracted[counter] = key;
			++counter;
		}
		else
		{
			for (size_t j = 0; j < quantity; ++j)
			{
				extracted[counter] = key;
				++counter;
			}
			++i;
		}
		
	}

	return extracted;
}
