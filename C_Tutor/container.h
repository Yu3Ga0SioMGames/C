#ifndef CONTAINER_H_INCLUDED
#define CONTAINER_H_INCLUDED

#include <stddef.h>
#include <stdint.h>

typedef void* Container;
typedef void (*print_ptr)(Container);
typedef size_t (*length_ptr)(Container);
typedef int (*append_ptr)(Container, int64_t);
typedef int (*prepend_ptr)(Container, int64_t);
typedef int (*insert_ptr)(Container, size_t, int64_t);
typedef int (*delete_ptr)(Container, size_t);
typedef int (*get_ptr)(Container, size_t, int64_t *);

typedef
struct {
    print_ptr print;
    length_ptr length;
    append_ptr append;
    prepend_ptr prepend;
    insert_ptr insert;
    delete_ptr delete;
    get_ptr get;
} ContainerMTable;

void print(Container obj);
int append(Container obj, int64_t data);
int prepend(Container obj, int64_t data);
size_t length(Container obj);
int insert(Container obj, size_t index, int64_t data);
int delete(Container obj, size_t index);
int get(Container obj, size_t index, int64_t *rv);

#endif
