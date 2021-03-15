#include "Vector.h"
#include <iostream>

void allocateMemory(Vector &vector, size_t capacity)
{
	vector.array = new int[capacity];
	vector.capacity = capacity;
}

void freeMemory(Vector &vector)
{
	delete[] vector.array;
}

void reallocateMemory(Vector &vector, size_t newCapacity)
{
	freeMemory(vector);
	allocateMemory(vector, newCapacity);
}

void resize(Vector &vector, int newCapacity)
{
	vector.capacity = newCapacity == 0 ? vector.capacity * 2 : newCapacity;
	int *newArray = new int[vector.capacity];
	for (size_t i = 0; i < vector.size; i++)
	{
		newArray[i] = vector.array[i];
	}
	freeMemory(vector);
	vector.array = newArray;
}

void print(const Vector &vector)
{
	for (int i = 0; i < vector.size; i++)
	{
		std::cout << vector.array[i] << std::endl;
	}
}

// void addElement(Vector &vector, int newElement)
// {
// 	if (vector.size >= vector.capacity)
// 	{
// 		resize(vector);
// 	}
// 	vector.array[vector.size++] = newElement;
// }

// void addElement(Vector &vector, int newElement, int position)
// {
// 	if (position >= vector.capacity)
// 	{
// 		resize(vector);
// 		addElement(vector, newElement, position);
// 	}
// 	else
// 	{
// 		for (int i = position; i <= vector.size; i++)
// 		{
// 			vector.array[i + 1] = vector.array[i];
// 		}
// 		vector.array[position] = newElement;
// 	}
// }

bool addElement(Vector &vector, int newElement)
{
	if (vector.size < vector.capacity)
	{
		vector.array[vector.size++] = newElement;
		return true;
	}
	return false;
}

bool addElement(Vector &vector, int newElement, int position)
{
	if (position < vector.capacity)
	{
		for (int i = position; i <= vector.size; i++)
		{
			vector.array[i + 1] = vector.array[i];
		}
		vector.array[position] = newElement;
		return true;
	}
	return false;
}

bool removeElement(Vector &vector, int position)
{
	if (position < vector.size)
	{
		int index = 0;
		for (int i = position; i < vector.size; i++)
		{
			vector.array[i] = vector.array[i + 1];
		}
		vector.size--;
		return true;
	}
	return false;
}