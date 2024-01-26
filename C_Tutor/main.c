#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define ND_CREATE_ERROR 1
#define BAD_POS_ERROR (ND_CREATE_ERROR + 1)


typedef
struct _node {
    int64_t data;
    struct _node *next;
} Node;

Node *create_node(int64_t);

void free_node(Node *);

void print_list(Node *);

int insert_to_list(Node **, size_t, int64_t);

int prepend_to_list(Node **, int64_t);

int delete_from_list(Node **, size_t);

size_t list_length(Node *);

int append_to_list(Node **, int64_t);

int get_from_list(Node *, size_t, int64_t *);

Node *get_node_from_list(Node *, size_t);

int main() {
    Node *list = NULL;
    for(int64_t i = 0; i < 5; ++i){
        prepend_to_list(&list, i);
    }
    print_list(list); // 4 3 2 1 0
    delete_from_list(&list, 3);
    print_list(list); // 4 3 2 0
    delete_from_list(&list, 4);
    print_list(list); // 4 3 2 0
    delete_from_list(&list, 0);
    print_list(list); // 3 2 0
    delete_from_list(&list, 2);
    print_list(list); // 3 2
    delete_from_list(&list, 0);
    delete_from_list(&list, 0);
    print_list(list); //
    delete_from_list(&list, 0);
    print_list(list); //
    return 0;
}

Node *create_node(int64_t input_data) {
    Node *node = (Node *)malloc(sizeof(Node));
    if(node == NULL) {
        return NULL;
    }

    node->data = input_data;
    node->next = NULL;
    return node;
}

void free_node(Node *input_node) {
    free(input_node);
}

int append_to_list(Node **list, int64_t data) {
    Node *new_node = create_node(data);
    if(new_node == NULL) {
        return ND_CREATE_ERROR;
    }

    Node *next_node = *list;
    if(next_node != NULL) {
        while (next_node->next != NULL) {
            next_node = next_node->next;
        }
        next_node->next = new_node;
    }
    else {
        *list = new_node;
    }
    return 0;
}

void print_list(Node *list) {
    while(list != NULL) {
        printf("%lld ", list->data);

        list = list->next;
    }
    printf("\n");
}

Node *get_node_from_list(Node *current_node, size_t index) {
    for(; index != 0 && current_node != NULL; --index) {
        current_node = current_node->next;
    }
    return current_node;
}

int get_from_list(Node *list, size_t index, int64_t *return_value) {
    Node *node_ptr = get_node_from_list(list, index);
    if(node_ptr != NULL) {
        *return_value = node_ptr->data;
        return 0;
    }
    else {
        return 1;
    }
}

int insert_to_list(Node **list, size_t index, int64_t data) {
    if(index == 0) {
        return prepend_to_list(list, data);
    }
    Node *new_node = create_node(data);
    if(new_node == NULL) {
        return ND_CREATE_ERROR;
    }
    Node *prev_node = get_node_from_list(*list, index - 1);
    if(prev_node == NULL) {
        return BAD_POS_ERROR;
    }
    new_node->next = prev_node->next;
    prev_node->next = new_node;
    return 0;
}

int prepend_to_list(Node **list, int64_t data) {
    Node *new_node = create_node(data);
    if(new_node == NULL) {
        return ND_CREATE_ERROR;
    }
    new_node->next = *list;
    *list = new_node;
    return 0;
}

int delete_from_list(Node **list, size_t index) {
    if(*list == NULL) {
        return BAD_POS_ERROR;
    }
    Node *current_node;
    if(index == 0) {
        current_node = *list;
        *list = current_node->next;
    }
    else {
        Node *prev_node = get_node_from_list(*list, index - 1);
        if(prev_node == NULL) {
            return BAD_POS_ERROR;
        }
        current_node = prev_node->next;
        if(current_node == NULL) {
            return BAD_POS_ERROR;
        }
        prev_node->next = current_node->next;
    }
    free_node(current_node);
    return 0;
}

size_t list_length(Node *list) {
    size_t count = 0;
    while(list == NULL) {
        list = list->next;
        ++count;
    }
    return count;
}
