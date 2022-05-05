#include "data.h"

data *Integer(int number){
    int *newInteger = (int *)malloc(sizeof(int));
    *newInteger = number;
    data *newData = (data *)malloc(sizeof(data));
    newData->ptr = newInteger;
    newData->size = sizeof(int);
    
    return newData;
}

void readData(data *targetData){
    unsigned char* p = (unsigned char*)targetData->ptr;
    for(int i=0;i<targetData->size;i++){
        printf("%#x", *(p+i));
    }
    printf("\n");
}
