#ifndef DATASTRUCTURE_OBJECT_H
#define DATASTRUCTURE_OBJECT_H

typedef struct Object{
    void (*to_string)(struct Object *);
}Object;

typedef struct Integer {
    Object super;
    int data;
}Integer;

typedef struct Character {
    Object super;
    char data;
}Character;

void integer_to_string(Object *super);
void character_to_string(Object *super);
Integer *init_integer(int value);
Character *init_character(char value);

#endif //DATASTRUCTURE_OBJECT_H
