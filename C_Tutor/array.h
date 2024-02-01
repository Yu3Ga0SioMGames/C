#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdint.h>

typedef
struct _Array {
    int64_t *dataArray;
    size_t length;
    size_t allocated;
} Array;

Array *create_array(size_t);

#endif // ARRAY_H_INCLUDED
