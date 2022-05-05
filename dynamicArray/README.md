## dynamicArray
### implementing python's list object using C lang

able to append and pop different type of Object type obejects infinitely <Br>
currently I only implemented the Integer Object.. <Br>

### ADT of dynamic array

```c
dynamicArray* initArray(); // create empty array with size of 2
int getArraySize(dynamicArray *targetArray); // get number of elements in the array
void resizeArray(dynamicArray *targetArray); // double the capacity of the targetArray 
void appendArray(dynamicArray *targetArray, data *object); // push back object to targetArray
data *popArray(dynamicArray *targetArray); // pop the last object and return it
data *removeArray(dynamicArray *targetArray, int index); // remove and return the object in the index
void insertArray(dynamicArray *targetArray, int index, data *object); // insert obejct to the index
```

### example
main.c
```c
#include <stdlib.h>
#include "object.h"
#include "dynamicArray.h"

int main() {
    dynamicArray *list = initArray();
    appendArray(list, Integer(1));
    appendArray(list, Integer(2));
    appendArray(list, Integer(3));
    appendArray(list, Integer(4));
    free(popArray(list));
    free(removeArray(list, 0));
    insertArray(list, 0, Integer(10));
    for(int i=0;i<list->top + 1;i++){
        readData(list->elements[i]);
    }
}
```
