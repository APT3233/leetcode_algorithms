/*
    Vector C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct vector
{
    void* arr;
    int length;
    int element_size;

    void (* push)(struct vector*, void *); // Đây là con trỏ hàm có thể trỏ tới một hàm có
                            //  hai tham số: con trỏ đến struct vector và con trỏ void*
    void (* remove)(struct vector*, int);
    void (* insert)(struct vector*, int, void*);
    void (* print)(struct vector*, void (* print_func)(void*));
    void (* free)(struct vector*);
    void* (* find)(struct vector* , void*);
    
} vector;

void vector_push(vector* v, void* value){
    v->arr = realloc(v->arr, (v->length+1) * v->element_size);
    memcpy((char*)v->arr + v->length * v->element_size,
                    value, v->element_size);
    v->length++;
}

void vector_delete_by_index(vector* v, int index){
    if (index >= v->length || index < 0) {
        printf("Index out of range\n");
        return;
    }

    //  di chuyển tất cả các phần tử từ vị trí index + 1 về trước một vị trí, 
    // đè lên phần tử tại vị trí index, hiệu ứng là xóa phần tử tại vị trí index.
    memmove((char*)v->arr + index * v->element_size,
            (char*)v->arr + (index + 1) * v->element_size,
            (v->length - index - 1 ) * v->element_size);
    
    v-> arr = realloc(v->arr, v->length * v->element_size);
    v->length--;
}

void vector_insert(vector* v, int index, void* value){
    if (index >= v->length || index < 0) {
        printf("Index out of range\n");
        return;
    }

    v->arr = realloc(v->arr, (v->length+1) * v ->element_size);
    memmove((char*)v->arr + (index + 1) * v->element_size,
            (char*)v->arr + index * v->element_size,
            (v->length - index) * v->element_size);

    memcpy((char*)v->arr + index * v->element_size,
            value,
            v->element_size);

    v->length++;
}
void* vector_find(vector* v, void* value) {
    for (int i = 0; i < v->length; i++) {
        if (memcmp((char*)v->arr + i * v->element_size, value, v->element_size) == 0) {
            return (char*)v->arr + i * v->element_size;
        }
    }
    return NULL;
}
void vector_print(vector* v, void (* print_func)(void*)){
    for(int i = 0; i < v->length; i++){
        print_func((char*)v->arr + i * v->element_size);
    }
    printf("\n");
}

void print_int(void* n) {
    printf("%d ", *(int*)n);
}
void print_float(void* n) {
    printf("%f ", *(float*)n);
}
void print_char(void* n) {
    printf("%c ", *(char*)n);
}

void vector_free(vector* v){
    free(v->arr);
    v->arr = NULL;
    v->length = 0;
    v->element_size = 0;
}

void vector_init(vector* v, int element_size){
    v->arr = NULL;
    v->length = 0;
    v->element_size = element_size;
    v->push = vector_push;
    v->remove = vector_delete_by_index;
    v->insert = vector_insert;
    v->print = vector_print;
    v->find = vector_find;
    v->free = vector_free;
}

int main(){
    srand(time(NULL));
    vector v;
    vector_init(&v, sizeof(int));
    for (int i = 0; i < 10; i++) {
        int rand_val = rand() % 100 + 1;
        v.push(&v, &rand_val);
    }
    
    printf("Before insertion: ");
    v.print(&v, print_int);

    int new_value = 500;
    v.insert(&v, 5, &new_value); // Chèn giá trị 500 vào vị trí thứ 5

    printf("After insertion: ");
    v.print(&v, print_int); 

    v.remove(&v, 0); // Xóa phần tử ở vị trí thứ 0

    printf("After deletion: ");
    v.print(&v, print_int);

    printf("Search value 500 is position: ");
    int find = 500;
    int* result =(int*)v.find(&v, &find);
    int index = result - (int*)v.arr;
    printf("%d\n", index);

    v.free(&v);

    printf("Test Done!\n");

    return 0;

}