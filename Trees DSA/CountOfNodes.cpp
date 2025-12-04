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

int nodecount(node *root){
    if(root == nullptr){
        return 0;
    }

    int leftCount = nodecount(root->left);
    int rightCount = nodecount(root->right);
    return leftCount + rightCount + 1;
}

int main()
{
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    node *root = buildtree(arr);

    cout << nodecount(root) << endl;
    return 0;
}