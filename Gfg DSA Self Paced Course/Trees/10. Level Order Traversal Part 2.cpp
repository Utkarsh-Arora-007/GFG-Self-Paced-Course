#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        right = left = NULL;
    }
};

void printLevel(Node *root)
{
    if(root == NULL) return;
    queue<Node *>q;
    q.push(root);

    while(q.empty()==false)
    {
        int count  = q.size();
        //Here in for loop we will not use the directly q.size(), we will use count var because if we directly use q.size(), the queue size will change dyanmically and there is a chance to that the "\n" will not come in proper place.
        for(int i=0; i<count; i++)
        {
            Node *curr = q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL)
              q.push(curr->left);

            if(curr->right!=NULL)
              q.push(curr->right);  

        }
        cout<<"\n";
    }
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    printLevel(root);
}