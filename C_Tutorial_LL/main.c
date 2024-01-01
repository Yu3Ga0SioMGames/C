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

int main(){
    Node test;
    test.data = 9;
    Node *ptr = &test;
    printf("%I64d\n", (*ptr).data);
    Node *new_node = create_node(8);
    if (new_node == NULL){
        printf("\nError: Unable to create new node.\n");
    }
    else{
        printf("\n%I64d\n", new_node->data);
        free(new_node);
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
