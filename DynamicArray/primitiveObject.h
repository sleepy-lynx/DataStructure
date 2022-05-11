#ifndef DATASTRUCTURE_PRIMITIVEOBJECT_H
#define DATASTRUCTURE_PRIMITIVEOBJECT_H

#include "object.h"
#include "myString.h"

typedef struct Integer {
    Object super;
    int data;
}Integer;

typedef struct Character {
    Object super;
    char data;
}Character;

String* integer_to_string(Object *super);
String* character_to_string(Object *super);
Integer *init_integer(int value);
Character *init_character(char value);

#endif //DATASTRUCTURE_PRIMITIVEOBJECT_H
