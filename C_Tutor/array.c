#include <stdlib.h>

#include "array.h"


Array *create_array(size_t initial_size) {
    Array *new_array = (Array *)malloc(sizeof(Array));
    if(new_array == NULL) {
        ;
    }
    new_array->dataArray = malloc(sizeof(int64_t) * initial_size);
    if(new_array->dataArray == NULL) {
        ;
    }
    new_array->allocated = initial_size;
    new_array->length = 0;
}
