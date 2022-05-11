#ifndef dynamicArray_h
#define dynamicArray_h
#include "object.h"
#define INIT_DYNAMIC_ARRAY_CAPACITY 4

typedef struct DynamicArray{
    Object super;
    Object **elements;
    int capacity;
    int top;
    int (*get_size)(struct DynamicArray*);
    void (*resize)(struct DynamicArray*, int);
    void (*append)(struct DynamicArray*, Object *);
    void (*pop)(struct DynamicArray*);
}DynamicArray;

DynamicArray *init_dynamic_array();
int dynamic_array_get_size(DynamicArray *this);
void dynamic_array_resize(DynamicArray *this, int value);
void dynamic_array_append(DynamicArray *this, Object *new_element);
void *dynamic_array_pop(DynamicArray *this);
void dynamic_array_to_string(Object *obj);
#endif /* dynamicArray_h */
