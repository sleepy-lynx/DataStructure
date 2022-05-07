#include "Object.h"

Integer *initInteger() {
    Integer *newInteger = (Integer *)malloc(sizeof(Integer));
    Object *super = (Object *)newInteger;
    super->toString = integerToString;
    super->equals = integerEquals;
    newInteger->setValue = integerSetValue;
    newInteger->data = INIT_INTEGER_DATA;

    return newInteger;
}

char* integerToString(Object *super) {
    Integer *this = (Integer *)super;
    char *ret = (char *) malloc(sizeof(char) * 256);
    sprintf(ret, "%d", this->data);
    return ret;
}

int integerEquals(Object *super, Object *targetSuper) {
    Integer *this = (Integer *)super;
    Integer *target = (Integer *)targetSuper;
    if(this->data == target->data) return 1;
    return 0;
}

void integerSetValue(Integer *this, int value) {
    this->data = value;
}

Object *initObject() {
    Object *newObject = (Object *)malloc(sizeof(Object));
    newObject->toString = objectToString;
    newObject->equals = objectEquals;

    return newObject;
}

char *objectToString(Object *this) {
    char *ret = (char *)malloc(sizeof(char) * 256);
    sprintf(ret, "%p", &this);
    return ret;
}

int objectEquals(Object *this, Object *target) {
    if(this == target) return 1;
    return 0;
}