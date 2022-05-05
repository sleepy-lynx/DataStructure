#include "dynamicArray.h"

void appendArray(dynamicArray *targetArray, data *object) {
    if(getArraySize(targetArray) == targetArray->size) resizeArray(targetArray);
    targetArray->top++;
    targetArray->elements[targetArray->top] = object;
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

void insertArray(dynamicArray *targetArray, int index, data *object) {
    if(index == targetArray->top) return appendArray(targetArray, object);
    for(int i=index + 1;i< getArraySize(targetArray);i++){
        targetArray->elements[i] = targetArray->elements[i - 1];
    }
    targetArray->elements[index] = object;
    targetArray->top++;
}

data *removeArray(dynamicArray *targetArray, int index) {
    if(index == targetArray->top) return popArray(targetArray);
    data *ret = targetArray->elements[index];
    for(int i=index;i<getArraySize(targetArray) - 1;i++) {
        targetArray->elements[i] = targetArray->elements[i + 1];
    }
    targetArray->top--;
    return ret;
}