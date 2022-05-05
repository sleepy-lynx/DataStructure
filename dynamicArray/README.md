# dynamicArray
### implementing python's list object using C lang

able to append and pop different type of Object type obejects infinitely <Br>
currently I only implemented the Integer Object.. <Br>

### ADT of dynamic array

```c
dynamicArray* initArray(); // create empty array with size of 2
int getElementNum(dynamicArray *targetArray); // get number of elements in the array
void resizeArray(dynamicArray *targetArray); // double the capacity of the targetArray 
void appendArray(dynamicArray *targetArray, object *object); // push back object to targetArray
object *popArray(dynamicArray *targetArray); // pop the last object and return it
object *removeArray(dynamicArray *targetArray, int index); // remove and return the object in the index
void insertArray(dynamicArray *targetArray, int index, object *object); // insert obejct to the index
```

### example
main.c
```c
#include "object.h"
#include "dynamicArray.h"

int main() {
    dynamicArray *list = initArray();
    for(int i=0;i<10;i++) appendArray(list, Integer(i));
    popArray(list);
    insertArray(list, 0, Integer(11));
    removeArray(list, 1);

    for(int i=0;i< getElementNum(list);i++){
        readData(list->elements[i]);
    }
}
```
output
```
0xb000
0x1000
0x2000
0x3000
0x4000
0x5000
0x6000
0x7000
0x8000
```
