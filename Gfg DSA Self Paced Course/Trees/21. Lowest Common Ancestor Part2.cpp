//Assumption that the node to be searched is strictly present.
//Requires only one traversal and O(h) extra space, where h = height of binary tree.
//This will not work or give wrong results if n1 or n2 any of them is not present. 

//Main Idea behind this approach : We do normally recursive traversal, we have the foll. cases for every node : 
//   1. If it is same as n1 or n2.
//   2. If one of its subtrees contains n1 and other contains n2.
//   3. If one of its subtrees contains both n1 and n2.
//   4. If none of its subtrees contain any of n1 and n2.

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

Node *lca(Node *root,int n1, int n2)
{
    if(root == NULL) return NULL;
    if(root->key == n1|| root->key == n2)
     return root;

    Node *lca1 = lca(root->left,n1,n2);
    Node *lca2 = lca(root->right,n1,n2);

    if(lca1!=NULL && lca2!=NULL)
    return root;

    if(lca1!=NULL)
    return lca1;
    else 
    return lca2; 
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    int n1 =20, n2 = 50;

    Node *ans = lca(root,n1,n2);
    cout<<"LCA: "<<ans->key;
}