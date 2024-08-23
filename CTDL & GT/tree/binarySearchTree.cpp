/*
    Basic Binary Search Tree C++
*/

#include <iostream>

using namespace std;

template <typename T>
struct Node{
    T data;
    Node* left;
    Node* right;
    Node(T value)
        : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
struct Tree{
    Node<T>* root;

    Tree(T value) : root(new Node(value)) {}

    void traverse_preorder(Node<T>* n) {
        if(n == nullptr)    return;
        cout << n->data << ' ';
        traverse_preorder(n->left);
        traverse_preorder(n->right);
    }
    void traverse_postorder (Node<T>* n, int level = 0) {
        if(n==nullptr)  return;
        traverse_postorder(n->left);
        traverse_postorder(n->right);
        cout << n->data << ' ';
    }
    void traverse_inorder(Node<T>* n) {
        if(n==nullptr)  return;

        traverse_inorder(n->left);
        cout << n->data << ' ';
        traverse_inorder(n->right);
    }

    void print(){
        cout << "\nPreorder: ";
        traverse_preorder(root);
        cout << "\nPostorder: ";
        traverse_postorder(root);
        cout << "\nInorder: ";
        traverse_inorder(root);
        cout<<endl;
    }

    Node<T>* _insert(Node<T>* node, T value){
        if(node == nullptr)
            return new Node(value);

        if(value < node->data)
            node->left = _insert(node->left, value);
        else
            node->right = _insert(node->right, value);
        
        return node;
    }
    void insert(T value){
        _insert(root, value);
    }

    Node<T>* _search(Node<T>* node, T value){
        if(node==nullptr)
            return nullptr;

        if(node->data == value)
            return node;
        
        if(value < node->data)
            return _search(node->left, value);
        else
            return _search(node->right, value);
    }
    Node<T>* search(T value){
        return _search(root, value);
    }

    Node<T>* find_leftmost(Node<T>* node){
        Node<T>* current = node;
        while(current->left != nullptr && current != nullptr)
            current = current->left;
        
        return current;
        
    }
    Node<T>* _remove(Node<T>* node, T value){
        if(node == nullptr) return nullptr;
        
        if(node->data == value){    
            // case1: left = null
            if(node->left == nullptr){
                Node<T>* tmp = node->right;
                delete node;
                return tmp;
            }
            // case2: right = null
            if(node->right == nullptr){
                Node<T>* tmp = node->left;
                delete node;
                return tmp;
            } 

            // case 3: complex
            else{
                Node<T>* tmp = node->right;
                Node<T>* leftmost_node = find_leftmost(tmp);
                leftmost_node->left = node->left;
                delete node;
                return tmp;
            }
        }
        else if(value < node->data)
            node->left = _remove(node->left, value);
        else 
            node->right = _remove(node->right, value);
        
        return  node;
    }
    void remove(T value){
        _remove(root, value);
    }

     
};
int main() {

    Tree<int> tree(1);
    for (int i = 2; i < 10; i++)
        tree.insert(i*2);
    

    tree.remove(4);
    tree.print();
    cout << (tree.search(4) ? "Found 4" : "Not found 4") << endl;
    
    return 0;
}

