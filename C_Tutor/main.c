#include <stdint.h>

#include "list.h"


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
