#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node* next;
    Node(T value) : data(value), next(NULL) {}
};

template<typename T>
struct LinkedList{
    Node<T>* head;
    int length;
    
    LinkedList() : head(NULL), length(0) {}

    void print_all(){
        for(Node<T>* node = head; node != NULL; node = node->next)
            cout << node->data << ' ';
        
        cout << endl;
    }

    T& operator[](int index){
        if (index < 0 || index >= length) 
            throw out_of_range("Index out of range");

        if (head == nullptr) 
            throw runtime_error("Cannot access element in an empty list");
    
        int i = 0;
        for(Node<T>* node = head; node != nullptr; node=node->next){
            if(i == index)
                return node->data;
            i++;
        }

        throw runtime_error("This line should never be reached"); 
    }

    void push_back(T value){
        Node<T>* new_node = new Node<T>(value);

        if(head == NULL){
            head = new_node;
            length++;
            return;
        }

        Node<T>* tmp = head;
        // for(; tmp->next != NULL; tmp = tmp->next){}
        while(tmp->next != NULL){
            tmp = tmp->next;
        }
        tmp->next = new_node;
        length++;
    }

    void erase(int index){
        if(index > length - 1 || index < 0){
            cout << "Out of Range\n";
            return;
        }

        if(index == 0){
            Node<T>* node = head;
            head = node->next;
            delete node;
        }
        else{
            int i = 1;
            Node<T>* node = head->next; // 1
            Node<T>* node_back = head;  // 0
            while(node != NULL){
                if(i == index){
                    node_back->next = node->next;
                    delete node;
                    break;
                }
                node_back = node;
                node = node->next;
                i++;
            }
        }


        length--;
    }

    void insert(int index, T value){
        if(index < 0 )
            throw out_of_range("Index out of range");
        if(head == NULL && index != 0)
            throw runtime_error("Cannot insert element in an empty list");
        
        if (index == 0) {
            Node<T>* new_node = new Node<T>(value);
            new_node->next = head;
            head = new_node;
            length++;
            return;
        }

        int i = 0;
        Node<T>* node = head;
        while(node != NULL && i < index - 1){
            node = node->next;
            i++;
        }
        if(node != NULL){
            Node<T>* new_node = new Node<T>(value);
            new_node->next = node->next;
            node->next = new_node;
            length++;
        }else   throw out_of_range("Index out of range\n");
    }

};





int main(){

   LinkedList<string> linked;
   linked.push_back("1");
   linked.push_back("2");
   linked.push_back("3");
   linked.push_back("4");
   //linked[2] = "passed";

   //cout << linked[2];

   linked.erase(1);
   linked.insert(2, "6");

   linked.print_all();



    return 0;
}