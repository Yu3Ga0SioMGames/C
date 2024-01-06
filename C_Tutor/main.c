#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef
struct _node{
    int64_t data;
    struct _node *next;
} Node;

Node *create_node(int64_t);
void *free_node(Node*);

void print_list(Node*);

//void append_to_list();

//void insert_in_list();

//void prepend_to_list();

//void delete_from_list();

void add_to_list(Node**, int64_t);

int get_from_list(Node*, size_t, int64_t*);

Node *get_node_from_list(Node*, size_t);

int main(){
    Node *list = NULL;
    for (int64_t i = 0; i < 10; ++i){
        add_to_list(&list, i);
    }
    print_list(list);
    int64_t value;
    size_t n;
    printf("\n");
    scanf("%zd", &n);
    int return_code = get_from_list(list, n, &value);
    if (return_code == 0){
        printf("\n%lld\n", value);
    }
    else{
        printf("\nElement not found!\n");
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

void add_to_list(Node** list, int64_t data){
    Node *new_node = create_node(data);
    if (new_node == NULL){
        return;
    }

    Node* next_node = *list;
    if (next_node != NULL){
        while (next_node->next != NULL){
            next_node = next_node->next;
        }
        next_node->next = new_node;
    }
    else{
        *list = new_node;
    }
}

void print_list(Node* list){
    while (list != NULL){
        printf("%lld, ", list->data);

        list = list->next;
    }
    printf("\n");
}

//Получает ноду - структуру из списка по заданному номеру.
Node *get_node_from_list(Node* current_node, size_t index){
    for (; index != 0 && current_node != NULL; --index){
        current_node = current_node->next;
    }
    return current_node;
}

//Получает данные из списка по заданному номеру. Эквивалентно: list[index]
int get_from_list(Node *list, size_t index, int64_t *return_value){
    Node *node_ptr = get_node_from_list(list, index);
    if (node_ptr != NULL){
        *return_value = node_ptr->data;
        return 0;
    }
    else{
        return 1;
    }
}

/*void append_to_list(){

}

void insert_in_list(){

}

void prepend_to_list(){

}

void delete_from_list(){

}*/
