#include "Object.h"

Integer *initInteger() {
    Integer *newInteger = (Integer *)malloc(sizeof(Integer));
    Object *super = (Object *)newInteger;
    super->toSting = integerToString;
    super->equals = integerEquals;
    newInteger->setValue = setValue;
    newInteger->data = INIT_INTEGER_DATA;
}

char* integerToString(Object *super) {
    Integer *this = (Integer *)super;
    char *ret = (char *) malloc(sizeof(char) * 256);
    sprintf(ret, "%d", this->data);
    return ret;
}

void setValue(Integer *this, int value) {
    this->data = value;
}

Object *initObject() {
    Object *newObject = (Object *)malloc(sizeof(Object));
    newObject->toSting = objectToString;
    newObject->equals = objectEquals;
}

char *objectToString(Object *this) {
    char *ret = (char *)malloc(sizeof(char) * 256);
    sprintf(ret, "%p", &this);
    return ret;
}

int *objectEquals(Object *this, Object *target) {
    if(this == target) return 1;
    return 0;
}