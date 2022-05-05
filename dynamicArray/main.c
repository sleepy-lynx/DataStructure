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
