/*
    Queue C
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    void* data;
    struct Node* next;
} Node;

typedef struct Queue{
    Node* head;
    Node* tail;
    int length;
} Queue;

void queue_init(Queue* q);
void enqueue(Queue* q, void* value);
void* dequeue(Queue* q);
void* front(Queue* q);
void* back(Queue* q);
bool isEmpty(Queue* q);
int size(Queue* q);

int main(){

    // Test Case
    Queue q;
    queue_init(&q);

    int a = 10, b = 20, c = 30;
    
    enqueue(&q, &a);
    enqueue(&q, &b);
    enqueue(&q, &c);

    printf("Front element: %d\n", *(int*)front(&q));
    printf("Back element: %d\n", *(int*)back(&q));
    
    printf("Dequeue element: %d\n", *(int*)dequeue(&q));
    printf("Front element after dequeue: %d\n", *(int*)front(&q));
    printf("Queue size: %d\n", size(&q));
    printf("Is queue empty? %s\n", isEmpty(&q) ? "Yes" : "No");

    return 0;
}


void queue_init(Queue* q){
    q->head = NULL;
    q->tail = NULL;
    q->length = 0;
}
void enqueue(Queue* q, void* value){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;
    if(q->head == NULL){
        q->head = new_node;
        q->tail = new_node;
    }
    else{
        q->tail->next = new_node;
        q->tail = new_node;
    }
    q->length++;
}
void* dequeue(Queue* q){
    if(q->head == NULL){
        printf("Queue is an empty\n");
        return NULL;
    }
    Node* tmp = q->head;
    void* result = tmp->data;
    q->head = q->head->next;
    q->length--;
    free(tmp);
    return result;
}

void* front(Queue* q){
    if(q->head == NULL){
        printf("Queue is an empty\n");
        return NULL;
    }
    return q->head->data;
}
void* back(Queue* q){
    if(q->head == NULL){
        printf("Queue is an empty\n");
        return NULL;
    }
    return q->tail->data;
}
bool isEmpty(Queue* q){
    return q->length == 0;
}
int size(Queue* q){ return q->length; }