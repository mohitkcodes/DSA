#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node (int n ){
    data = n;
    left = right = nullptr;
    }
};

node *insert(node *root, int val){
    if(root == nullptr) return new node(val);

    if(val<root->data){
        root->left = insert(root->left,val);
    }
    else {
        root->right = insert(root->right, val);
    }
    return root;
}

//boolen search
bool search(node *root, int key){
    if(root == nullptr){
        return false;
    } if (root->data == key){
        return true;
    } if(root->data > key ){
       return search(root->left , key);
    } else {
       return search(root->right, key);
    }
}

int findmin(node *root){
    while(root->left != nullptr){
        root = root->left;
    }
    return root->data;
}

int findmax (node *root ){
    while(root->right != nullptr){
        root = root->right;
    }
    return root->data;
}

void inorder(node *root){
    if(root == nullptr) return;
    inorder(root->left);
    cout << root -> data << " ";
    inorder(root->right);
}

int main()
{
    node *root = nullptr;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    inorder(root);

    cout << endl << search(root , 0) << endl;
    cout << findmax(root) << endl;
    cout << findmin(root) << endl;
    
    return 0;
}