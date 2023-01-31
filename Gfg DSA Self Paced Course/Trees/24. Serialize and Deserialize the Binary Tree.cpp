//serialization code : to convert binary tree to a string
//Time Complexity :  Theta(N)
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

const int EMPTY = -1;
void serialize(Node *root, vector<int> &arr)
{
    if(root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }
    arr.push_back(root->key);
    serialize(root->left,arr);
    serialize(root->right,arr);
}

int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    vector<int> arr;
    serialize(root, arr);
    for(int x : arr){
        cout<<x<<" ";
    }
}



//Deserialize the tree : Converting string to a binary Tree
//Time Complexity : Theta(N)

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

const int EMPTY = -1;
void serializeable(Node *root, vector<int> &arr)
{
    if(root == NULL)
    {
        arr.push_back(EMPTY);
        return;
    }

    arr.push_back(root->key);
    serializeable(root->left,arr);
    serializeable(root->right,arr);
}

Node *deSerialize(vector<int> &arr, int &index){

    if(index == arr.size())
        return NULL;

    int val = arr[index];
    index++;
    if(val == EMPTY) return NULL;
    Node *root = new Node(val);  // Preorder Traversal
    root->left = deSerialize(arr,index);
    root->right = deSerialize(arr, index);
    return root;

}

void inorder(Node *root)
{
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);

    vector<int> arr;
    serializeable(root, arr);
    for(int x : arr){
        cout<<x<<" ";
    }

    cout<<endl;
    int index = 0;
    Node *root_new = deSerialize(arr, index);
    inorder(root_new);

}
