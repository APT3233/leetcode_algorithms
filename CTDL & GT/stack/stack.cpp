/*
    Basic Stack C++    
*/

#include <iostream>
#include <time.h>

using namespace std;

template<typename T>
struct Stack{
    T* arr;
    int length;
    int capacity;

    Stack() : length(0), capacity(10){ arr = new T[capacity];}
    ~Stack() { delete[] arr; }

    T& operator[](T index){
        if (index < 0 || index >= length) 
            throw out_of_range("Index out of range");
        
        return arr[index];
    }

    void resize(){
        int newSpace = capacity*2;
        T* tmp = new T[newSpace];
        for (int i = 0; i < length; i++)
            tmp[i] = arr[i];

        delete[] arr;
        arr = tmp;
        capacity = newSpace;
    }
    void push(T value){
        if(arr == nullptr){
            arr = new T[1];
            arr[0] = value;
            length++;
            return;
        }
        if(length == capacity)
            resize();

        arr[length++] = value;
    }

    T pop(){
        if(arr == nullptr){
            cout<<"Stack is an Empty\n";
            return T();
        }
        T res = arr[length-1];
        
        T* tmp = new T[length-1];
        for (int i = 0; i < length-1; i++)
            tmp[i] = arr[i];
        
        delete[] arr;
        arr = tmp;
        length--;

        return res;
    }

    T top(){
        if(arr == nullptr){
            cout<<"Stack is an Empty\n";
            return T();
        }   
        return arr[length-1];
    }

    bool isEmpty(){
        return length==0;
    }
};

int main(){
    srand(time(nullptr));
    Stack<int> s;
    for(int i = 1; i <= 10; i++)
        s.push(rand() % 100 + 1);

    cout<<(s.isEmpty() ? "Is empty\n" : "Is available\n");
    for (int i = 0; i < s.length; i++)
        cout<<s[i]<<' ';

    s.pop();
    cout<< "\nTop element after pop: "<< s.top();

    cout<<"\nlength: "<<s.length;
    cout<<"\ncapacity: "<<s.capacity;
    cout<<endl;

    return 0;
    
}