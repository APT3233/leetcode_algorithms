/*
    Basic Stack C
*/

#include <stdio.h>
#include <stdlib.h> // malloc
#include <stdbool.h>  // bool
#include <string.h> // strdup
#include <time.h>

typedef struct {
    void** arr;
    int length;
    int capacity;
} Stack;

void init(Stack* s);
void resize(Stack* s);
void push(Stack* s, void* value);
void* pop(Stack* s);
void* top(Stack* s);
bool isEmpty(Stack* s);
void freeStack(Stack* s);

int main(){
    Stack s;
    init(&s);
       
    int a = 10;
    float b = 20.5;
    char c = 'c';

    push(&s, &a);
    push(&s, &b);
    push(&s, &c);

    printf("Top element: %c\n", *(char*)top(&s));
    pop(&s);
    printf("Top element: %.2f\n", *(float*)top(&s));
    pop(&s);
    printf("Top element: %d\n", *(int*)top(&s));
    pop(&s);

}

void init(Stack* s){
    s->length = 0;
    s->capacity = 10;
    s->arr = (void**)malloc(s->capacity * sizeof(void*));
}

void resize(Stack* s){
    int newSpace = s->capacity * 2;
    void** tmp = (void**)malloc(newSpace * sizeof(void*));
    for (int i = 0; i < s->length; i++)
        tmp[i] = s->arr[i];
    
    free(s->arr);
    s->arr = tmp;
    s->capacity = newSpace;
}

void push(Stack* s, void* value){
    if(s->arr == NULL){
        s->arr = (void**)malloc(sizeof(void*));
        s->arr[0] = strdup(value);
        s->length++;
        return;
    }

    if(s->length == s->capacity)
        resize(s);

    s->arr[s->length++] = strdup(value);
}

void* pop(Stack* s) {
    if (s->arr == NULL || s->length == 0) {
        printf("Stack is empty\n");
        return NULL;
    }
    void* res = s->arr[s->length - 1];
    s->length--;
    return res;
}
void* top(Stack* s){
    if (s->arr == NULL || s->length == 0) {
        printf("Stack is empty\n");
        return NULL;
    }
    
    return s->arr[s->length-1];
}

bool isEmpty(Stack* s) { return s->length == 0; }   

void freeStack(Stack* s){
    for (int i = 0; i < s->length; i++)
        free(s->arr[i]);
    
    free(s->arr);
}