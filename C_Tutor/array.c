#include <stdio.h>
#include <stdlib.h>

#include "array.h"


Array *create_array(size_t initial_size) {
    Array *new_array = (Array *)malloc(sizeof(Array));
    if(new_array == NULL) {
        return NULL;
    }
    new_array->dataArray = malloc(sizeof(int64_t) * initial_size);
    if(new_array->dataArray == NULL) {
        free(new_array);
        return NULL;
    }
    new_array->allocated = initial_size;
    new_array->length = 0;
    return new_array;
}

void free_array(Array *array) {
    free(array->dataArray);
    free(array);
}

void print_array(Array *array) {
    for(size_t i = 0; i < array->length; ++i) {
        printf("%lld ", array->dataArray[i]);
    }
    printf("\n");
}

size_t array_length(Array *array) {
    return array->length;
}

int extend_array(Array *array) {
    size_t new_size = array->allocated * 2;
    int64_t *new_mem = (int64_t *)malloc(sizeof(int64_t) * new_size);
    if(new_mem == NULL) {
        return BAD_ALLOCATION_ERROR;
    }

    for(size_t i = 0; i < array->allocated; ++i) {
        new_mem[i] = array->dataArray[i];
    }

    free(array->dataArray);

    array->dataArray = new_mem;
    array->allocated = new_size;
    return 0;
}

int append_to_array(Array *array, int64_t data) {
    if(array->length == array->allocated) {
        int rc = extend_array(array);
        if(rc != 0) {
            return EXTENTION_ERROR;
        }
    }
    array->dataArray[array->length] = data;
    array->length++;
    return 0;
}

int insert_to_array(Array *array, size_t index, int64_t data) {
    if(index > array->length) {
        return INDEX_OUT_OF_BOUNDS;
    }

    if(array->length == array->allocated) {
        int rc = extend_array(array);
        if(rc != 0) {
            return EXTENTION_ERROR;
        }
    }

    for(size_t i = array->length; i > index; --i) {
        if(index == array->length) {
            append_to_array(array, data);
        }
        else {
            array->dataArray[i] = array->dataArray[i - 1];
        }
    }

    array->dataArray[index] = data;
    array->length++;
    return 0;
}
