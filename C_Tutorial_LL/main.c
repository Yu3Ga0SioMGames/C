#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef
struct _node{
    int64_t data;
    struct _node *next;
} Node;

/*Объявление функции состоит из:
1.) Тип возращаемого значения;
2.) Имя функции;
3.) Список параметров;*/
Node *create_node(int64_t);

void *free_node(Node*);

void add_to_list(Node*, int64_t);

int main(){
    Node *list = NULL;
    for (int64_t i = 0; i < 10; ++i){
        add_to_list(list, i);
    }
    return 0;
}

Node *create_node(int64_t input_data){
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL){
        return NULL;
    }

    node->data = input_data;
    node->next = NULL;
    return node;
}

void *free_node(Node* input_node){
    free(input_node);
}

void add_to_list(Node* list, int64_t data){
    Node *new_node = create_node(data);
    if (new_node == NULL){
        return;
    }

    Node* next_node = list;
    while (next_node->next != NULL){
        next_node = next_node->next;
    }

    next_node->next = new_node;
}
