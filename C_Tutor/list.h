#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "container.h"

#define ND_CREATE_ERROR 1
#define BAD_POS_ERROR (ND_CREATE_ERROR + 1)

typedef
struct _node {
    int64_t data;
    struct _node *next;
} Node;

typedef
struct {
    ContainerMTable container;
    size_t length;
    Node *first;
    Node *last;
} List;

List *create_list();
List free_list(List *);

Node *create_node(int64_t);
Node *get_node_from_list(Node *, size_t);

void free_node(Node *);
void print_list(Node *);

int insert_to_list(Node **, size_t, int64_t);
int prepend_to_list(Node **, int64_t);
int delete_from_list(Node **, size_t);

size_t list_length(Node *);

int append_to_list(Node **, int64_t);
int get_from_list(Node *, size_t, int64_t *);

#endif
