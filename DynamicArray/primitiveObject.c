#include "primitiveObject.h"
#include <stdio.h>
#include <stdlib.h>

String* integer_to_string(Object *super) {
    char tmp[256];
    Integer *this = (Integer *)super;
    sprintf(tmp, "%d, ", this->data);
    return init_string(tmp);
}

String* character_to_string(Object *super) {
    char tmp[256];
    Character *this = (Character *)super;
    sprintf(tmp, "'%c', ", this->data);
    return init_string(tmp);
}

Integer *init_integer(int value) {
    Integer *this = (Integer *)malloc(sizeof(Integer));
    this->super.to_string = integer_to_string;
    this->data = value;
    return this;
}

Character *init_character(char value) {
    Character *this = (Character *)malloc(sizeof(Integer));
    this->super.to_string = character_to_string;
    this->data = value;
    return this;
}