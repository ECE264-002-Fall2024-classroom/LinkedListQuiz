#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

// helper functions
static LinkedNode* create_node(int value) {
    LinkedNode* new_node = (LinkedNode*)malloc(sizeof(LinkedNode));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

static void free_list(LinkedNode* head) {
    LinkedNode* current = head;
    while (current != NULL) {
        LinkedNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    
    LinkedNode* head = NULL;
    LinkedNode* tail = NULL;
    int number;
    while (fscanf(file, "%d", &number) == 1) {
        LinkedNode* new_node = create_node(number);
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    fclose(file);
    
    linked_list_counter(head); // your function
    
    free_list(head);
    
    return EXIT_SUCCESS;
}