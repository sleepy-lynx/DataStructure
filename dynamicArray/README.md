# dynamicArray
### implementing python's list object using C lang

able to append and pop different type of Object type obejects infinitely <Br>
currently I only implemented the Integer Object.. <Br>

### ADT of dynamic array

```c
dynamicArray* initArray(); // generate dynamic array and initialize it
int len(dynamicArray *targetArray); // return the size of the array(need to be fixed after implementing iterator
void resizeArray(dynamicArray *targetArray); // double the capacity of the array
void append(dynamicArray *targetArray, DATA object); // add an element at the end
DATA pop(dynamicArray *targetArray); // get the last element and pop it
void insert(dynamicArray *targetArray, int index, DATA object); // insert element to the index position
DATA removeIdx(dynamicArray *targetArray, int index); // remove element at the index position
```

### example
main.c
```c
int main() {
    dynamicArray *l = initArray();
    for(int i=0;i<10;i++) append(l, i);
    pop(l);
    insert(l, 0, 10);
    removeIdx(l, 1);
    for(int i=0;i<len(l);i++) printf("%d ", l->elements[i]);
}
```
output
```
10 1 2 3 4 5 6 7 8 
```
