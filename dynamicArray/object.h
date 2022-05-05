#ifndef data_h
#define data_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void *ptr;
    int size;
}data;
data *Integer(int number);
void readData(data *targetData);
#endif /* data_h */
