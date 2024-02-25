#include <stdint.h>

#include "array.h"


int main() {
    Array *array;

    size_t initial_size;

    printf("Введите размер массива: ");
    scanf("%zu", &initial_size);
    array = create_array(initial_size);

    for (int i = 0; i < initial_size; ++i) {
        append_to_array(array, i);
    }

    print_array(array); // 0 1 2 3 4 ...

    int rc = insert_to_array(array, 5, 5);
    if(rc != 0) {
        return EXTENTION_ERROR;
    }

    print_array(array); // 0 1 2 3 4 5 ...

    insert_to_array(array, 7, 7);
    print_array(array); // 0 1 2 3 4 5 ...

    insert_to_array(array, 3, 7);
    print_array(array); // 0 1 2 7 3 4 5 ...

    insert_to_array(array, 0, -1);
    print_array(array); // -1 0 1 2 7 3 4 5 ...

    insert_to_array(array, 2, -2);
    print_array(array); // -1 0 -2 1 2 7 3 4 5 ...

    delete_from_array(array, 0);
    print_array(array); // 0 -2 1 2 7 3 4 5 ...

    delete_from_array(array, 4);
    print_array(array); // 0 -2 1 2 3 4 5 ...

    delete_from_array(array, 6);
    print_array(array); // 0 -2 1 2 3 4 ...

    int64_t rv_data;

    get_from_array(array, 2, &rv_data);

    printf("\n%lld\n", rv_data);

    free_array(array);
    return 0;
}
