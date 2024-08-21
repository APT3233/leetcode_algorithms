/*
    Queue C++
*/

#include <iostream>

using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
struct Queue {
    Node<T>* head;
    Node<T>* tail;
    int length;

    Queue() : head(nullptr), tail(nullptr), length(0) {}

    T& operator[](int index) {
        if (head == nullptr) 
            throw out_of_range("Queue is empty");
        
        Node<T>* current = head;
        for (int i = 0; i < index && current != nullptr; ++i) 
            current = current->next;
        
        if (current == nullptr) 
            throw out_of_range("Index out of bounds");
        
        return current->data;
    }

    void enqueue(T data) {
        Node<T>* new_node = new Node<T>(data);
        if (head == nullptr) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
        length++;
    }

    T dequeue() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return T(); // return default value of T
        }
        Node<T>* tmp = head;
        T res = head->data;
        head = head->next;
        delete tmp;
        length--;
        return res;
    }

    // first element
    T front() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return T(); 
        }
        return head->data;
    }

    // last element
    T back() {
        if (head == nullptr) {
            cout << "Queue is empty\n";
            return T(); 
        }
        return tail->data;
    }

    bool isEmpty()  { return length == 0; }

    int size() const { return length; }
};

int main() {
    Queue<int> q;

    // Enqueue elements
    for (int i = 1; i <= 10; ++i) {
        q.enqueue(i * 10);
    }

    // Print queue size
    cout << "Queue size: " << q.size() << endl;

    // Access elements using operator[]
    for (int i = 0; i < q.size(); ++i) 
        cout << "Element at index " << i << ": " << q[i] << endl;
    


    cout << "Front element: " << q.front() << endl;
    cout << "Back element: " << q.back() << endl;

    // Dequeue elements and print
    while (!q.isEmpty())
        cout << "Dequeued element: " << q.dequeue() << endl;
    

    // Attempt to dequeue from an empty queue
    q.dequeue();

    return 0;
}
