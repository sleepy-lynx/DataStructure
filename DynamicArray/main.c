#include "dynamicArray.h"
#include "object.h"
#include "myString.h"
#include <stdio.h>

int main() {
    DynamicArray *dynamic_array = init_dynamic_array();
    DynamicArray *tmp = init_dynamic_array();

    tmp->append(tmp, init_string("123"));
    tmp->append(tmp, init_integer(100));

    dynamic_array->append(dynamic_array, init_integer(0));
    dynamic_array->append(dynamic_array, init_integer(1));
    dynamic_array->append(dynamic_array, init_integer(2));
    dynamic_array->pop(dynamic_array);
    dynamic_array->append(dynamic_array, init_character('a'));
    dynamic_array->append(dynamic_array, tmp);
    dynamic_array->append(dynamic_array, init_string("Hello, String"));

    dynamic_array->super.to_string(dynamic_array);

}