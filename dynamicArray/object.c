#include "object.h"

object *Integer(int number){
    int *newInteger = (int *)malloc(sizeof(int));
    *newInteger = number;
    object *newData = (object *)malloc(sizeof(object));
    newData->ptr = newInteger;
    newData->size = sizeof(int);

    return newData;
}

void readData(object *targetData){
    unsigned char* p = (unsigned char*)targetData->ptr;
    for(int i=0;i<targetData->size;i++){
        printf("%#x", *(p+i));
    }
    printf("\n");
}
