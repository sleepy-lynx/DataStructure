#include "object.h"
#include <stdio.h>
#include <stdlib.h>

void object_to_string(Object *this) {
    printf("Object@%p, ", this);
}

void integer_to_string(Object *super) {
    Integer *this = (Integer *)super;
    printf("%d, ", this->data);
}

void character_to_string(Object *super) {
    Character *this = (Character *)super;
    printf("'%c', ", this->data);
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