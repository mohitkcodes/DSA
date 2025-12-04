#include<iostream>
#include<queue>
using namespace std;

class node {
    public:
    int data;
    node *left;
    node *right;

    node (int n){
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
//preorder traversal root-left-right
void preorder(node *root){
    if(root == nullptr){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    
}
//inorder traversal left-root-right
void inorder(node *root){
    if(root == nullptr){
        return;
    }
    preorder(root->left);
    cout<<root->data << " ";
    preorder(root->right);
    
}
//postorder traversal left-right-root
void postorder(node *root){
    if(root == nullptr){
        return;
    }
    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
    
}
//levelorder traversal
void levelorder(node *root){
    queue<node*> q;
    q.push(root);
    q.push(nullptr);
    
    while(q.size()>0){
        node *curr = q.front();
        q.pop();

        if(curr == nullptr){
            if(!q.empty()){
                cout << endl;
                q.push(nullptr);
                continue;
            } else {
                break ;
            }
        }

        cout << curr->data << " ";
        if(curr->left != nullptr){
            q.push(curr->left);
        }
        if(curr->right != nullptr){
            q.push(curr->right);
        }
    }
}

int main()
{
    int arr[] = {1,2,3,-1,-1,4,-1,-1,5,6,-1,-1,7,-1,-1};
    node *root = buildtree(arr);   
    preorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    levelorder(root);
    return 0;
}