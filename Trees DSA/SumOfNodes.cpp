#include<iostream>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node(int n){
        data = n;
        left = right = nullptr;
    }
};

static int ind = -1;
node *buildtree(int pre[]){
    ind++;
    if(pre[ind] == -1){
        return nullptr;
    }

    node *root = new node(pre[ind]);

    root->left = buildtree(pre);
    root->right = buildtree(pre);
    return root;
}

int Sum (node *root){
    if(root == nullptr){
        return 0;
    }

    int leftSum = Sum(root->left);
    int rightSum = Sum(root->right);

    return leftSum + rightSum + root->data;

}

int main()
{
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    node *root = buildtree(arr);   
    cout << Sum(root);
    return 0;
}