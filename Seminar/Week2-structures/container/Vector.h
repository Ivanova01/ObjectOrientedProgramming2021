#ifndef VECTOR_H
#define VECTOR_H
struct Vector
{
    int *array;
    size_t capacity;
    size_t size;
};

void allocateMemory(Vector &vector, size_t capacity);
void freeMemory(Vector &vector);
void reallocateMemory(Vector &vector, size_t newCapacity);
void resize(Vector &vector);

void print(const Vector &vector);

bool addElement(Vector &vector, int newElement);

bool addElement(Vector &vector, int newElement, int position);

bool removeElement(Vector &vector, int position);
#endif