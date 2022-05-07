#include "Object.h"

int main() {
    Object *o1 = initObject();
    Object *o2 = initObject();
    Integer *i1 = initInteger();
    Integer *i2 = initInteger();
    i1->setValue(i1 ,10);

    printf("Integer toString function output -> %s\n", i1->super.toString(i1));
    printf("is i1 i2 equal? -> %d \n\n", i2->super.equals(i1, i1));

    printf("Object toString function output -> %s\n", o1->toString(o1));
    printf("is o1 o2 equal? -> %d", i2->super.equals(o2, o1));
}