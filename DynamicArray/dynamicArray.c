#include "dynamicArray.h"
#include <stdlib.h>
#include <stdio.h>

DynamicArray *init_dynamic_array() {
    DynamicArray *this = (DynamicArray *)malloc(sizeof(DynamicArray));
    this->elements = (Object **)malloc(sizeof(Object *) * INIT_DYNAMIC_ARRAY_CAPACITY);
    this->capacity = INIT_DYNAMIC_ARRAY_CAPACITY;
    this->top = -1;
    this->get_size = dynamic_array_get_size;
    this->resize = dynamic_array_resize;
    this->append = dynamic_array_append;
    this->pop = dynamic_array_pop;
    this->super.to_string = dynamic_array_to_string;

    return this;
}

int dynamic_array_get_size(DynamicArray *this) {
    return this->top + 1;
}

void dynamic_array_resize(DynamicArray *this, int value) {
    Object **new_array = (Object **)malloc(sizeof(Object *) * value);
    for(int i=0;i<this->get_size(this);i++){
        new_array[i] = this->elements[i];
    }
    free(this->elements);
    this->elements = new_array;
    this->capacity = value;
}

void dynamic_array_append(DynamicArray *this, Object *new_element) {
    if(this->get_size(this) == this->capacity) this->resize(this, this->capacity * 2);
    this->elements[++this->top] = new_element;
}

void *dynamic_array_pop(DynamicArray *this) {
    free(this->elements[this->top]);
    this->top--;
}

void dynamic_array_to_string(Object *obj) {
    DynamicArray *l = (DynamicArray *)obj;
    printf("[");
    for(int i=0;i<l->get_size(l);i++){
        l->elements[i]->to_string(l->elements[i]);
    }
    printf("] ");
}