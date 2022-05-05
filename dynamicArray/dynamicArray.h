//
//  dynamicArray.h
//  PS
//
//  Created by 혜승 on 2022/05/04.
//

#ifndef dynamicArray_h
#define dynamicArray_h
#define DEFAULT_ARRAY_SIZE 16

#include <stdio.h>
#include <stdlib.h>
#include "data.h"

typedef struct {
    data **elements;
    int size;
    int top;
}dynamicArray;

void append(dynamicArray *targetArray, data *targetData);
dynamicArray* initArray(void);

#endif /* dynamicArray_h */
