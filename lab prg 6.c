#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void ins_at_pos_n(struct Node** head_ref, int data, int position) {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    int i;
    struct Node *temp = *head_ref;
    if (position == 1) {
        ptr->next = temp;
        *head_ref = ptr;
        return;
    }
    for (i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nCannot insert at position %d (Out of bounds)\n", position);
        free(ptr);
        return;
    }
    ptr->next = temp->next;
    temp->next = ptr;
}

void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
    return;
}

void printList(struct Node *node) {
    if (node == NULL) {
        printf("Empty List\n");
        return;
    }
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    printf("--- Singly Linked List: Insertion Operations ---\n");
    append(&head, 6);
    printf("After appending 6: ");
    printList(head);
    push(&head, 7);
    printf("After pushing 7 at beginning: ");
    printList(head);
    push(&head, 1);
    printf("After pushing 1 at beginning: ");
    printList(head);
    append(&head, 4);
    printf("After appending 4 at end: ");
    printList(head);
    ins_at_pos_n(&head, 15, 3);
    printf("After inserting 15 at position 3: ");
    printList(head);
    return 0;
}

