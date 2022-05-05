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
