#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int n){
        data = n;
        left = right = nullptr;
    }
};

node *insert(node *root, int val){
    if(root == nullptr) return new node(val);

    if(val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(node *root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int preorder = 0;
//kth smallest bst
int kthsmallest(node *root, int k){
    if(root == nullptr) return -1;

    if(root->left != nullptr){
        int leftAns = kthsmallest(root->left,k);
        if(leftAns != -1){
            return leftAns;
        }
    }

    if(preorder + 1 == k){
        return root->data;
    }

    if(root->right != nullptr){
        int rightAns = kthsmallest(root->right,k);
        if(rightAns != -1){
            return rightAns;
        }
    }

    return -1;
}

int main()
{

    node *root = nullptr;
    root = insert(root , 50);
    root = insert(root , 60);
    root = insert (root , 0);

    inorder(root);

    
    return 0;
}