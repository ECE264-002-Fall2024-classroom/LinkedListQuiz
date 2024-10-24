#ifndef HELPER_H
#define HELPER_H

// DO NOT MODIFY THIS FILE

// Node structure for the linked list
typedef struct LinkedNode {
    int data;
    struct LinkedNode* next;
} LinkedNode;

// Your function
void linked_list_counter(LinkedNode* head);

#endif // HELPER_H
