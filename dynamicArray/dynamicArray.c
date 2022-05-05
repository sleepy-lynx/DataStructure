#include "dynamicArray.h"

void append(dynamicArray *targetArray, data *targetData) {
    targetArray->top++;
    targetArray->elements[targetArray->top] = targetData;
}

dynamicArray* initArray(void){
    dynamicArray *newArray = (dynamicArray *)malloc(sizeof(dynamicArray));
    newArray->size = DEFAULT_ARRAY_SIZE;
    newArray->elements = (data **)malloc(sizeof(data *) * DEFAULT_ARRAY_SIZE);
    newArray->top = -1;
    return newArray;
}

void resizeArray(dynamicArray *targetArray, int targetSize) {
    targetArray->elements = (data **)malloc(sizeof(data *) * (targetArray->size * 2));
    
}
