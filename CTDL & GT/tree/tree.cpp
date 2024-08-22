/*
    Basic Tree C++
    use: DFS
*/
#include <iostream>
#include <string.h>

using namespace std;

template <typename T>
struct Node
{
    T data;
    Node* left;
    Node* right;
    Node(T value) 
    : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
struct Tree
{
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

};


int main(){
    Tree tree(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);

    tree.print();
}

