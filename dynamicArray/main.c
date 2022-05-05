#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "data.h"
#include "dynamicArray.h"

int main() {
    dynamicArray *list = initArray();
    append(list, Integer(1));
    append(list, Integer(2));
    append(list, Integer(3));
    append(list, Integer(4));
    for(int i=0;i<list->top + 1;i++){
        readData(list->elements[i]);
    }
}
