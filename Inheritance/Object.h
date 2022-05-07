#ifndef DATASTRUCTURE_OBJECT_H
#define DATASTRUCTURE_OBJECT_H

#include <stdlib.h>
#include <stdio.h>
#define INIT_INTEGER_DATA 0

typedef struct Object{
    char* (*toString)(struct Object *);
    int (*equals)(struct Object *, struct Object *);
}Object;

typedef struct Integer{
    Object super;
    void (*setValue)(struct Integer*, int);
    int data;
}Integer;

Integer *initInteger();
char* integerToString(Object *super);
int integerEquals(Object *super, Object *targetSuper);
void integerSetValue(Integer *this, int value);
Object *initObject();
char *objectToString(Object *this);
int objectEquals(Object *this, Object *target);

#endif //DATASTRUCTURE_OBJECT_H
