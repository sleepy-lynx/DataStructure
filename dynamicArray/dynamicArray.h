#ifndef dynamicArray_h
#define dynamicArray_h
#define DEFAULT_ARRAY_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

typedef struct {
    data **elements;
    int size;
    int top;
}dynamicArray;

void appendArray(dynamicArray *targetArray, data *object);
int getArraySize(dynamicArray *targetArray);
void resizeArray(dynamicArray *targetArray);
dynamicArray* initArray();
data *popArray(dynamicArray *targetArray);
data *removeArray(dynamicArray *targetArray, int index);
void insertArray(dynamicArray *targetArray, int index, data *object);

#endif /* dynamicArray_h */
