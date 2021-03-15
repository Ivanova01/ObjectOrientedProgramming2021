#include <iostream>
#include "Vector.h"

int main()
{
    // dynamically allocated array which can be resized
    int *array{nullptr};

    // capacity of the array
    size_t capacity = 3;

    // exact number of elements in the array
    size_t size = 0;

    Vector vector{array, capacity, size};

    allocateMemory(vector, capacity);

    addElement(vector, 1);
    addElement(vector, 2);
    addElement(vector, 3);

    std::cout << "The capacity of the array is " << vector.capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << vector.size << std::endl;
    print(vector);

    addElement(vector, 4, 2);

    std::cout << "\nThe capacity of the array is " << vector.capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << vector.size << std::endl;
    print(vector);

    removeElement(vector, 0);
    removeElement(vector, 0);

    std::cout << "\nThe capacity of the array is " << vector.capacity << std::endl;
    std::cout << "The real count of the elements in the array is " << vector.size << std::endl;

    print(vector);

    freeMemory(vector);
    return 0;
}