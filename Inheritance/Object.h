#ifndef DATASTRUCTURE_OBJECT_H
#define DATASTRUCTURE_OBJECT_H

#include <stdlib.h>
#include <stdio.h>
#define INIT_INTEGER_DATA 0

typedef struct {
    char* (*toSting)(struct Object *tmp);
    int (*equals)(struct Object *tmp, struct Object *tmpTarget);
}Object;

typedef struct {
    Object super;
    void (*setValue)(struct Integer *this, int value);
    int data;
}Integer;

Integer *initInteger();
char* integerToString(Object *super);
int integerEquals(Object *super, Object *targetSuper);
void setValue(Integer *this, int value);
Object *initObject();
char *objectToString(Object *this);
int *objectEquals(Object *this, Object *target);

#endif //DATASTRUCTURE_OBJECT_H
