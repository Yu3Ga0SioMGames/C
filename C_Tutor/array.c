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

    new_array->mtbl.print = (print_ptr)print_array;
    new_array->mtbl.append = (append_ptr)append_to_array;
    new_array->mtbl.length = (length_ptr)array_length;
    new_array->mtbl.prepend = (prepend_ptr)prepend_to_array;
    new_array->mtbl.insert = (insert_ptr)insert_to_array;
    new_array->mtbl.delete = (delete_ptr)delete_from_array;
    new_array->mtbl.get = (get_ptr)get_from_array;
    return new_array;
}

void free_array(Array *array) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

    free(array->dataArray);
    free(array);
}

void print_array(Array *array) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

    for(size_t i = 0; i < array->length; ++i) {
        printf("%lld ", array->dataArray[i]);
    }
    printf("\n");
}

size_t array_length(Array *array) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

    return array->length;
}

int extend_array(Array *array) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

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
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

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

int prepend_to_array(Array *array, int64_t data) {
    return insert_to_array(array, 0, data);
}

int insert_to_array(Array *array, size_t index, int64_t data) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

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
        array->dataArray[i] = array->dataArray[i - 1];
    }

    array->dataArray[index] = data;
    array->length++;
    return 0;
}

int delete_from_array(Array *array, size_t index) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

    if(index > array->length) {
        return INDEX_OUT_OF_BOUNDS;
    }

    for(size_t i = index; i < array->length - 1; ++i) {
        array->dataArray[i] = array->dataArray[i + 1];
    }

    array->length--;
    return 0;
}

int get_from_array(Array *array, size_t index, int64_t *rv) {
    if(array == NULL) {
        return ARRAY_NOT_PROVIDED;
    }

    if(index > array->length) {
        return INDEX_OUT_OF_BOUNDS;
    }

    *rv = array->dataArray[index];
    return 0;
}
