#ifndef DATASTRUCTURE_MYSTRING_H
#define DATASTRUCTURE_MYSTRING_H

#include "object.h"
#include "dynamicArray.h"

typedef struct String {
    DynamicArray super;
    void (*print_string)(struct String*)
}String;

String *init_string(char *value);
void string_print_string(String *this);
void string_to_string(Object *this, char *buffer);

#endif //DATASTRUCTURE_MYSTRING_H
