#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *head = NULL;
struct Node *current = NULL;

void print_list() {
    struct Node *ptr = head;

    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct Node* delete_node(int key) {
    struct Node* current = head;
    struct Node* previous = NULL;

    if(head == NULL) {
        return NULL;
    }

    while(current->data!= key) {
        if(current->next == NULL) {
            return NULL;
        }
        else {
            previous = current;
            current = current->next;
        }
    }

    if (current == head) {
        head = head->next;
    }
    else {
        previous->next = current->next;
    }
    return current;
}

void insert_node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));

    node->data = data;
    node->next = head;
    head = node;
}

int main() {
    insert_node(3);
    insert_node(8);
    insert_node(56);
    insert_node(73);
    insert_node(80);

    printf("List consist of: ");
    print_list();

    printf("Type in the element you want to delete: ");
    int n;
    scanf("%d", &n);

    delete_node(n);

    printf("List after erasement: ");
    print_list();

    return 0;
}
