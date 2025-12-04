#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node * right;

    node(int n){
        data = n;
        left = right = nullptr;
    }
};

static int ind = -1;

node * BuildTree(int pre[]){
    ind++;
    
    if(pre[ind] == -1){
        return nullptr;
    }

    node *root = new node(pre[ind]);
    root->left = BuildTree(pre);
    root->right = BuildTree(pre);

    return root;

}

int main()
{
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    node *root = BuildTree(arr);
    cout << root->data << endl;
    return 0;
}