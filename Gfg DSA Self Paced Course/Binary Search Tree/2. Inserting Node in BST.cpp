// Recursive Solution
//Time Complexity: O(h) and Space Complexity : O(h)
// h: height of the BST , in case of Self Balancing BST, h = log(n)

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right =  NULL;
    }
};

Node * insert(Node *root, int x)
{
    if(root == NULL)
       return new Node(x);

    if(root->key < x)
    {
        root->right = insert(root->right,x);
    }
    else if(root->key > x)
    {
        root->left = insert(root->left, x);
    }

    return root;
}

void inorder(Node *root)
{
    if(root !=NULL)
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

    int x = 20;
    root = insert(root, x);
    inorder(root);
}



//Iterative Solution
//Time Complexity : O(h)
//Space Complexity : O(1) ,no extra space required.

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

Node *insert(Node *root, int x)
{
    Node *temp = new Node(x);
    Node *parent = NULL, *curr = root;

    while(curr != NULL)
    {
        parent  = curr;
        if(curr->key > x)
        {
            curr = curr->left;
        }

        else if(curr->key < x)
        {
            curr = curr->right;
        }

        else
         return root;   // If root value is same as the value to be inserted
        
    }

    if(parent  == NULL)  // If the root is NULL (i.e. Tree is empty)
    return temp;

    if(parent->key > x)
        parent->left = temp;

    else
       parent->right = temp;

   return root;       
}

void inorder(Node *root)
{
    if(root!=NULL)
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

    int x = 20;
    root = insert(root , x);
    inorder(root);
}