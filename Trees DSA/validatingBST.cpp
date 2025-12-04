#include<iostream>
using namespace std;

class node{
    public:
    int data ;
    node *left;
    node *right;

    node(int n){
        data = n;
        left = right = nullptr;
    }
};

node *insert(node *root,int val){
    if(root == nullptr) return new node (val);
    if(val<root->data){
        root->left = insert(root->left , val);
    } else{
        root->right = insert(root->right,val);
    }
    return root;
}

bool helper(node *root, node *min, node *max){
    if(root == nullptr){
        return true;
    } if(min != nullptr && root->data <= min->data){
        return false;
    } if(max != nullptr && root->data >= max->data){
        return false;
    } return helper(root->left , min, root) && helper (root->right , root, max);
}

bool isValidBST(node *root){
    return helper(root);
}
int main()
{
    
    return 0;
}