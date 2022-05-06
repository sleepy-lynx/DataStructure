#include "dynamicArray.h"

dynamicArray* initArray() {
    dynamicArray* newArray = (dynamicArray *)malloc(sizeof(dynamicArray));
    newArray->size = INIT_ARRAY_SIZE;
    newArray->elements = (DATA *)malloc(sizeof(DATA) * INIT_ARRAY_SIZE);
    newArray->top = -1;

    return newArray;
}

int len(dynamicArray *targetArray) {
    return targetArray->top + 1;
}

void resizeArray(dynamicArray *targetArray) {
    DATA *tmp = (DATA *)malloc(sizeof(DATA) * targetArray->size * 2);
    for(int i=0;i<len(targetArray);i++){
        tmp[i] = targetArray->elements[i];
    }
    free(targetArray->elements);
    targetArray->elements = tmp;
    targetArray->size = targetArray->size * 2;
}

void append(dynamicArray *targetArray, DATA object) {
    if(len(targetArray) == targetArray->size) resizeArray(targetArray);
    targetArray->elements[++targetArray->top] = object;
}

DATA pop(dynamicArray *targetArray) {
    return targetArray->elements[targetArray->top--];
}

void insert(dynamicArray *targetArray, int index, DATA object) {
    if(len(targetArray) == targetArray->size) resizeArray(targetArray);
    for(int i=len(targetArray);i>index;i--){
        targetArray->elements[i] = targetArray->elements[i - 1];
    }
    targetArray->elements[index] = object;
    targetArray->top++;
}

DATA removeIdx(dynamicArray *targetArray, int index) {
    for(int i=index;i<len(targetArray);i++){
        targetArray->elements[i] = targetArray->elements[i + 1];
    }
    targetArray->top--;
}