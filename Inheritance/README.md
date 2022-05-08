# Inheritance
### implementing Inheritance using C lang

able to create user defined structure and use parent's function and variable
currently not able to inherit multiple objects...<Br>
also it is not memory-safe. need to be auto collected using GC

### ADT
```c
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
```

### Example
main.c
```c
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
```
output
```
Integer toString function output -> 10
is i1 i2 equal? -> 1 

Object toString function output -> 0x7ff7b80c67d8
is o1 o2 equal? -> 0
```