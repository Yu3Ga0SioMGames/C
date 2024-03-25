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

int insert(Container obj, size_t index, int64_t data) {
    ContainerMTable *table = (ContainerMTable *)obj;
    return (table->insert)(obj, index, data);
}

int delete(Container obj, size_t index) {
    ContainerMTable *table = (ContainerMTable *)obj;
    return (table->delete)(obj, index);
}

int get(Container obj, size_t index, int64_t *rv) {
    ContainerMTable *table = (ContainerMTable *)obj;
    return (table->get)(obj, index, rv);
}
