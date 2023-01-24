// Naive Approach
// Time Complexity: O(n^2)
//becoz for each node there will be two recursion call in the recursion call stack : One will check is it balanced and other will tell you the level(height) of the node.

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

int height(Node *root)
{
    if(root == NULL)
        return 0;
    else
        return (1+max(height(root->left),height(root->right)));

}

bool isBalanced(Node *root)
{
    if(root == NULL)
       return true;

    int lh = height(root->left);
    int rh = height(root->right);
    return (abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right));   
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right =  new Node(20);

    cout<<isBalanced(root); 
}




//Method 2: Efficient Approach
// Time Complexity: O(N)
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int key; 
  struct Node *left; 
  struct Node *right; 
  Node(int k){
      key=k;
      left=right=NULL;
  }
};

int isBalancedd(Node *root)
{
    if(root == NULL)
       return 0;

    int lh = isBalanced(root->left);
    if(lh==-1) return -1;  // for the left height of the tree
    int rh = isBalanced(root->right);
    if(rh == -1) return -1;  // for the right height of the tree

    if(abs(lh-rh) > 1)
       return -1;

    else
       return max(lh,rh)+1;      
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    if(isBalancedd(root))
      cout<<"Balanced"<<"\n";

    else 
      cout<<"Not Balanced"<<"\n";  
}