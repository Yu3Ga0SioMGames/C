#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#define EXTENTION_ERROR 1
#define BAD_ALLOCATION_ERROR (EXTENTION_ERROR + 1)
#define INDEX_OUT_OF_BOUNDS (BAD_ALLOCATION_ERROR + 1)
#define ARRAY_NOT_PROVIDED (INDEX_OUT_OF_BOUNDS + 1)

#include <stdio.h>
#include <stdint.h>


typedef
struct _Array {
    int64_t *dataArray;
    size_t length;
    size_t allocated;
} Array;

Array *create_array(size_t);

void free_array(Array *);

void print_array(Array *);

size_t array_length(Array *);

int extend_array(Array *);

int append_to_array(Array *, int64_t);

int insert_to_array(Array *, size_t, int64_t);

int get_from_array(Array *, size_t, int64_t *);

#endif
