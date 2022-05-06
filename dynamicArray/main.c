#include "dynamicArray.h"

int main() {
    dynamicArray *l = initArray();
    for(int i=0;i<10;i++) append(l, i);
    pop(l);
    insert(l, 0, 10);
    removeIdx(l, 1);
    for(int i=0;i<len(l);i++) printf("%d ", l->elements[i]);
}
