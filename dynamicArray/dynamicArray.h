#ifndef dynamicArray_h
#define dynamicArray_h
#define DEFAULT_ARRAY_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct {
    data **elements;
    int size;
    int top;
}dynamicArray;

void append(dynamicArray *targetArray, data *targetData);
int getArraySize(dynamicArray *targetArray);
void resizeArray(dynamicArray *targetArray);
dynamicArray* initArray();

#endif /* dynamicArray_h */
