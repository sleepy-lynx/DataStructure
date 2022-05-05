#ifndef dynamicArray_h
#define dynamicArray_h
#define DEFAULT_ARRAY_SIZE 1

#include <stdio.h>
#include <stdlib.h>
#include "object.h"

typedef struct {
    object **elements;
    int size;
    int top;
}dynamicArray;

void appendArray(dynamicArray *targetArray, object *object);
int getElementNum(dynamicArray *targetArray);
void resizeArray(dynamicArray *targetArray);
dynamicArray* initArray();
object *popArray(dynamicArray *targetArray);
object *removeArray(dynamicArray *targetArray, int index);
void insertArray(dynamicArray *targetArray, int index, object *object);

#endif /* dynamicArray_h */
