//There are three main possibilities to delete a child in BST:
//1. Node to be deleted is a leaf Node.
//2. Node to be deleted has only one child.
//3. Node to be deleted has two children

//If we delete the root of the tree in case, then its inorder successor (Closest high Value) or inorder predecessor (closest low value), either of one can be replaced.


#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while(curr !=NULL && curr->left!=NULL)
    {
        curr = curr->left;
    }
    return curr;
}


Node *delNode(Node *root, int x)
{
    //This is for searching the target element
    if(root == NULL)
       return root;

    if(root->key > x)
       root->left = delNode(root->left,x);

    else if(root->key < x)
       root->right = delNode(root->right,x);

    // From here we will check the 3 main cases of deletion of nodes
    else {

        if(root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        else if(root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        else {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delNode(root->right, succ->key);
        }


    }
    return root;   
}

void inorder(Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    int x = 15;
    root = delNode(root, x);
    inorder(root);
}