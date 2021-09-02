#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node *next;
    struct Node *prev;
};

struct List {
    struct Node *head;
    struct Node *tail;
    int count;
} list;

void print_list() {
    struct Node *temp = list.head;
    for (int i = 0; i < list.count; i++) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

void insert_node(int v){
    struct Node* temp = malloc(sizeof(struct Node));
    temp->value = v;
    if (list.count == 0) {
        list.head = temp;
        list.tail = temp;
        list.count++;
    } else {
        temp->prev = list.tail;
        list.tail->next = temp;
        list.tail = temp;
        list.count++;
    }
}

void delete_node(int ind) {
    if (list.count > 0) {
        if (ind == 0 && list.count > 1) {
            struct Node *toDelete = list.head, *next = list.head->next;
            next->prev = NULL;
            list.head = next;
            list.count--;
            memset(toDelete, 0, sizeof(struct Node));
        }
        else if (ind == 0 && list.count == 1) {
            struct Node *toDelete = list.head;
            list.head = NULL;
            list.tail = NULL;
            list.count = 0;
            memset(toDelete, 0, sizeof(struct Node));
        }
        else if (ind > 0 && ind < list.count - 1) {
            struct Node *next, *current = list.head, *prev;
            for (int i = 0; i < ind; i++) {
                current = current->next;
            }
            next = current->next;
            prev = current->prev;
            next->prev = prev;
            prev->next = next;
            list.count--;
            memset(current, 0, sizeof(struct Node));
        }
        else if (ind == list.count - 1) {
            struct Node *toDelete = list.tail, *prev = list.tail->prev;
            prev->next = NULL;
            list.tail = prev;
            list.count--;
            memset(toDelete, 0, sizeof(struct Node));
        }
    }
}

int main() {
    // Example of using doubly linked list

    list.count = 0;

    insert_node(2);
    insert_node(8);
    insert_node(23);
    insert_node(45);
    insert_node(454);
    insert_node(87);
    insert_node(67);
    insert_node(1);
    
    printf("initial list:\n");
    print_list();

    delete_node(2);

    printf("Delete node with index 2\n");
    print_list();

    insert_node(23);

    printf("Insert node after node with index 6\n");
    print_list();
}
