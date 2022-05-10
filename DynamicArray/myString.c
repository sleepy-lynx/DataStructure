#include "myString.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

String *init_string(char *value) {
    String *this = (String *)malloc(sizeof(String));
    DynamicArray *l = &this->super;
    this->super = *init_dynamic_array();
    l->super.to_string = string_to_string;
    for(int i=0;i<strlen(value);i++) {
        l->append(l, init_character(value[i]));
    }
    return this;
}

void string_to_string(Object *obj, char *buffer) {
    DynamicArray *l = (DynamicArray *)obj;
    printf("\"");
    for(int i=0;i<l->get_size(l);i++){
        printf("%c", ((Character *)l->elements[i])->data);
    }
    printf("\", ");
}