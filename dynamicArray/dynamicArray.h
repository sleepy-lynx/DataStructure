#ifndef dynamicArray_h
#define dynamicArray_h

#include <stdio.h>
#include <stdlib.h>
#define DATA int
#define INIT_ARRAY_SIZE 2

typedef struct {
    DATA *elements;
    int size;
    int top;
}dynamicArray;

dynamicArray* initArray();
int len(dynamicArray *targetArray);
void resizeArray(dynamicArray *targetArray);
void append(dynamicArray *targetArray, DATA object);
DATA pop(dynamicArray *targetArray);
void insert(dynamicArray *targetArray, int index, DATA object);
DATA removeIdx(dynamicArray *targetArray, int index);

#endif /* dynamicArray_h */
