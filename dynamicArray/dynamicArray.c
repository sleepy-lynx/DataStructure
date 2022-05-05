#include "dynamicArray.h"

void appendArray(dynamicArray *targetArray, object *object) {
    if(getElementNum(targetArray) == targetArray->size) resizeArray(targetArray);
    targetArray->top++;
    targetArray->elements[targetArray->top] = object;
}

int getElementNum(dynamicArray *targetArray) {
    return targetArray->top + 1;
}

dynamicArray* initArray(void){
    dynamicArray *newArray = (dynamicArray *)malloc(sizeof(dynamicArray));
    newArray->size = DEFAULT_ARRAY_SIZE;
    newArray->elements = (object **)malloc(sizeof(object *) * DEFAULT_ARRAY_SIZE);
    newArray->top = -1;
    return newArray;
}

void resizeArray(dynamicArray *targetArray) {
    object **tmp = (object **)malloc(sizeof(object *) * targetArray->size * 2);
    for(int i=0; i < getElementNum(targetArray); i++){
        tmp[i] = targetArray->elements[i];
    }
    free(targetArray->elements);
    targetArray->elements = tmp;
    targetArray->size = targetArray->size * 2;
}

object *popArray(dynamicArray *targetArray) {
    object *ret = targetArray->elements[targetArray->top--];
    return ret;
}

void insertArray(dynamicArray *targetArray, int index, object *object) {
    if(getElementNum(targetArray) == targetArray->size) resizeArray(targetArray);
    if(index == targetArray->top) return appendArray(targetArray, object);
    for(int i= getElementNum(targetArray) + 1; i > index; i--){
        targetArray->elements[i] = targetArray->elements[i - 1];
    }
    targetArray->elements[index] = object;
    targetArray->top++;
}

object *removeArray(dynamicArray *targetArray, int index) {
    if(index == targetArray->top) return popArray(targetArray);
    object *ret = targetArray->elements[index];
    for(int i=index; i < getElementNum(targetArray) - 1; i++) {
        targetArray->elements[i] = targetArray->elements[i + 1];
    }
    targetArray->top--;
    return ret;
}