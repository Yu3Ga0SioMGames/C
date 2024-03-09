#include "container.h"

void print(Container obj) {
    ContainerMTable *table = (ContainerMTable *)obj;
    (table->print)(obj);
}

int append(Container obj, int64_t data) {
    ContainerMTable *table = (ContainerMTable *)obj;
    return (table->append)(obj, data);
}

size_t length(Container obj) {
    ContainerMTable *table = (ContainerMTable *)obj;
    return (table->length)(obj);
}

int prepend(Container obj, int64_t data) {
    ContainerMTable *table = (ContainerMTable *)obj;
    return (table->prepend)(obj, data);
}
