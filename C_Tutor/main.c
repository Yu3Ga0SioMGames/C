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

    print_array(array);
    return 0;
}
