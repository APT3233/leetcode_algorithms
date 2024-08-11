/*
    Linked List C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    int length;
} LinkedList;

void linkedList_init(LinkedList* list);
void print_all(LinkedList* list);
Node* get_element(LinkedList* list, int index);
void push_back(LinkedList* list, void* data);
void erase(LinkedList* list, int index);
void insert(LinkedList* list, int index, void* value);
void free_list(LinkedList* list);

int main(){
    LinkedList linked;
    linkedList_init(&linked);

    push_back(&linked, "1");
    push_back(&linked, "2");
    push_back(&linked, "3");
    push_back(&linked, "4");
    push_back(&linked, "5");

    erase(&linked, 1);
    insert(&linked, 2, "6");
    
    print_all(&linked);

    Node* res = get_element(&linked, 0);
    printf("%s\n", (char*)res->data);

    free_list(&linked);

    return 0;
}

void linkedList_init(LinkedList* list){
    list->head = NULL;
    list->length = 0;
}

void print_all(LinkedList* list){
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }
    Node* node = list->head;
    while(node != NULL){
        printf("%s ", (char*)node->data);
        node = node->next;
    }
    printf("\n");
}

Node* get_element(LinkedList* list, int index) {
    if (index < 0 || index >= list->length) {
        fprintf(stderr, "Out of range\n");
        return NULL;
    }
    if (list->head == NULL) {
        fprintf(stderr, "List is empty\n");
        return NULL;
    }
    int i = 0;
    Node* tmp = list->head;
    while (tmp != NULL) {
        if (i == index)
            return tmp;
        tmp = tmp->next;
        i++;
    }
    return NULL;
}


void push_back(LinkedList* list, void* value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = strdup(value);
    if (new_node->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for data\n");
        free(new_node);
        exit(1);
    }
    new_node->next = NULL;

    if(list->head == NULL)
        list->head = new_node;
    else{
        Node* tmp = list->head;
        while(tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new_node;
    }
    list->length++;
}

void erase(LinkedList* list, int index){
    if(index < 0 || index >= list->length){
        printf("Out of range\n");
        return;
    }
    if(list->head == NULL){
        printf("List is empty\n");
        return;
    }

    if (index == 0) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp->data);
        free(temp);
    } else {
        Node* prev = list->head;
        Node* current = list->head->next;
        for (int i = 1; i < index; i++) {
            prev = current;
            current = current->next;
        }
        prev->next = current->next;
        free(current->data);
        free(current);
    }
    list->length--;
}

void insert(LinkedList* list, int index, void* value) {
    if (index < 0 || index > list->length) {
        printf("Index out of range\n");
        exit(1);
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->data = strdup(value);
    if (new_node->data == NULL) {
        fprintf(stderr, "Error: Memory allocation failed for data\n");
        free(new_node);
        exit(1);
    }

    if (index == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node* prev = list->head;
        for (int i = 0; i < index - 1; i++) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
    list->length++;
}

void free_list(LinkedList* list) {
    Node* current = list->head;
    while (current != NULL) {
        Node* next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
    list->length = 0;
}
