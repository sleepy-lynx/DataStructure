#include <stdio.h>
#include <stdlib.h>
#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({ \
    void *__mptr = (void *)(ptr);          \
    ((type *)(__mptr - offsetof(type, member))); })
#define list_for_each(pos, head) for(pos = (head)->next; pos != head; pos = pos->next)

typedef struct list_head{
    struct list_head *next;
    struct list_head *prev;
}list_head;

typedef struct Object {
    int data;
    list_head list;
}Object;

void INIT_LIST_HEAD(list_head *head) {
    head->next = head;
    head->prev = head;
}

void list_add(list_head *list, list_head *head) {
    list->prev = head->prev;
    head->prev->next = list;
    list->next = head;
    head->prev = list;
}

int main() {
    Object *tmp;
    list_head head;
    INIT_LIST_HEAD(&head);
    for(int i=0;i<10;i++){
        tmp = (Object *)malloc(sizeof(Object));
        tmp->data = i;
        list_add(&tmp->list, &head);
    }

    list_head *pos;
    list_for_each(pos, &head) {
        tmp = container_of(pos, Object, list);
        printf("%d -> ", tmp->data);
    }
}