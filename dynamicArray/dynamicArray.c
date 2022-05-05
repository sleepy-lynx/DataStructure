#include "dynamicArray.h"

void append(dynamicArray *targetArray, data *targetData) {
    if(getArraySize(targetArray) == targetArray->size) resizeArray(targetArray);
    targetArray->top++;
    targetArray->elements[targetArray->top] = targetData;
}

int getArraySize(dynamicArray *targetArray) {
    return targetArray->top + 1;
}

dynamicArray* initArray(void){
    dynamicArray *newArray = (dynamicArray *)malloc(sizeof(dynamicArray));
    newArray->size = DEFAULT_ARRAY_SIZE;
    newArray->elements = (data **)malloc(sizeof(data *) * DEFAULT_ARRAY_SIZE);
    newArray->top = -1;
    return newArray;
}

void resizeArray(dynamicArray *targetArray) {
    data **tmp = (data **)malloc(sizeof(data *) * targetArray->size * 2);
    for(int i=0;i<getArraySize(targetArray);i++){
        tmp[i] = targetArray->elements[i];
    }
    free(targetArray->elements);
    targetArray->elements = tmp;
    targetArray->size = targetArray->size * 2;
}

data *popArray(dynamicArray *targetArray) {
    data *ret = targetArray->elements[targetArray->top--];
    return ret;
}