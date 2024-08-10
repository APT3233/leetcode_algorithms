#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


template<typename T>
struct vector{
    T* arr;
    int length;

    vector(){
        arr = nullptr;
        length = 0;
    }
    ~vector(){ delete[] arr;}

    T* begin() { return arr; }
    T* end() { return arr + length; }

    void push(T value){
        if(arr == nullptr){
            arr = new T[1];
            arr[0] = 0;
            length++;
            return;
        }

        T* arr_tmp = new T[length+1];
        int i = 0;
        while(arr[i] < value && i < length){
            arr_tmp[i] = arr[i];
            i++;
        }
        arr_tmp[i] = value;
        while (i < length)
        {
            arr_tmp[i+1] = arr[i];
            i++;
        }
        
        length++;
        delete[] arr;
        arr = arr_tmp;
    }

    T& operator[](int index){
        if(index >= length || index < 0)    
            throw out_of_range("Index out of range 1\n");

        return arr[index];
    }

    void insert(int index, T value){
        if(index >= length || index < 0)
            throw out_of_range("Index out of range 3\n");
        
        T* arr_tmp = new T[length];
        
        for(int i = 0; i < index-1; i++)
            arr_tmp[i] = arr[i];
        
        arr_tmp[index-1] = value;
        
        for (int i = index; i < length; i++)
            arr_tmp[i+1] = arr[i];
        
        length++;
        delete[] arr;
        arr = arr_tmp;
        cout << "Success\n";

    }

    void delete_by_index(int index){
        if(index >= length || index < 0)
            throw out_of_range("Index out of range 2\n");
        
        T* arr_tmp = new T[length-1];
        for(int i = 0, j = 0; i < length; i++){
            if(i != index)
                arr_tmp[j++] = arr[i];
        }
        length--;
        delete[] arr;
        arr = arr_tmp;
        cout << "Success\n";
    }

    T* find(int value){
        
        int left = 0;
        int right = length - 1; // binary search

        while(left <= right){
            int mid = left + (right-left) / 2;
            if(arr[mid] == value)
                return &arr[mid];

            if(arr[mid] > value)
                left = mid - 1;
            else 
                right = mid + 1;
        }

        return nullptr;
        
    }
    
};

int main(){
    vector<int> v;
    srand(time(0));
    cout << "Start Length: " << v.length << '\n';
    for(int i = 0; i < 10; i++){
        v.push(rand() % 100 + 1);
    }

    v[0] = 100;
    for(int x : v)
        cout << x << ' ';
    
    cout << "\nValue 0 position: " << v[0];

    cout << "\n[+] Delete element by Index 1: ";
    v.delete_by_index(1);

    cout << "\n[+] Insert index 5: ";
    v.insert(5, 500);

    for(int x : v)
        cout << x << ' ';

    cout << "Find value 500: ";
    int* result = v.find(500);
    int index = result - v.arr;
    cout << index << endl;
    

    cout << "\nEnd Length: " << v.length << '\n';
    
    return 0;
}