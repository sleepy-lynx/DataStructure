#ifndef data_h
#define data_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    void *ptr;
    int size;
}object;
object *Integer(int number);
void readData(object *targetData);
#endif /* data_h */
