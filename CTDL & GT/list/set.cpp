/*
    Set C++
*/

#include <iostream>
#include <time.h>
#include <unistd.h>

template<typename T>
struct Set
{
    T* arr;
    int length;

    Set() : arr(nullptr), length(0) {}
    ~Set()  {delete[] arr;}
    Set(const Set& other) : arr(nullptr), length(other.length) {
        if (other.arr != nullptr) {
            arr = new T[length];
            for (int i = 0; i < length; i++) {
                arr[i] = other.arr[i];
            }
        }
    }
    Set& operator=(const Set& other) {
        if (this != &other) {
            delete[] arr;  

            length = other.length;
            arr = new T[length];
            for (int i = 0; i < length; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    void print(){
        if(arr == nullptr){
            std::cout << "Empty Set\n";
            return;
        }
            
        for(int i = 0; i < length; i++){
            std::cout << arr[i] << ' ';
        }
        std::cout<<std::endl;
    }

    T& operator[](int index){
        if(index >= length || index < 0)    
            throw std::out_of_range("Index out of range\n");

        return arr[index];
    }

    void add(T value){
        if(arr == nullptr){
            arr = new T[1];
            arr[0] = value;
            length++;
            return;
        }
        for(int i = 0; i < length; i++){
            if(arr[i] == value){
                std::cout<<"Value is already present\n\n";
                return;
            }
        }

        T* tmp = new T[length+1];
        int i = 0;
        while(i<length){
            tmp[i] = arr[i];
            i++;
        }
        tmp[length++] = value;
        delete[] arr;
        arr = tmp;
    }
    void remove(int index){
        if(index < 0 || index > length-1){
            std::cout << "Out of range\n";
            return;
        }
        if(arr == nullptr){
            std::cout << "List is an empty\n";
            return;
        }
        T* tmp = new T[length-1];
        int i = 0;
        while(i < length && i < index){
            tmp[i] = arr[i];
            i++;
        }
        while (i < length-1)
        {
            tmp[i] = arr[i+1];
            i++;
        }
        delete[] arr;
        arr = tmp;
        length--;
    }

    Set intersection(const Set& other_set) {
        if (other_set.arr == nullptr || arr == nullptr) {
            std::cout << "One of the lists is empty\n";
            return *this;  
        }

        Set res;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < other_set.length; j++) {
                if (arr[i] == other_set.arr[j]) {
                    res.add(arr[i]);  
                }
            }
        }

        return res;  
    }
    
    Set union_set(const Set& other_set){
        if (other_set.arr == nullptr) return *this;
        if (arr == nullptr) return other_set;

        Set res;
        for (int i = 0; i < length; i++) 
            res.add(arr[i]);
        
        for (int j = 0; j < other_set.length; j++) {
            bool found = false;
            for (int i = 0; i < res.length; i++) 
                if (res.arr[i] == other_set.arr[j]) {
                    found = true;
                    break;
                }
            if (!found) 
                res.add(other_set.arr[j]);
        }

        return res; 
    }

};


int main(){
    srand(time(nullptr));

    Set<int> set;
    Set<int> set2;

    for(int i = 0; i < 10; i++){
        if(i%2 == 0)
            set2.add(i);
        set.add(i);
    }
 
    set.remove(2);

    std::cout<<"Set1: "; 
    set.print();
    std::cout<<"Set2: ";
    set2.print();

    Set unionSet = set.union_set(set2);

    std::cout << "Union of Set and Set2: ";
    unionSet.print();

    Set tmp = set.intersection(set2);

    std::cout<< "Intersection: ";
    for(int i = 0; i < tmp.length; i++){
        std::cout << tmp[i]<< ' ';
    }
    std::cout<<std::endl;

    return 0;
}