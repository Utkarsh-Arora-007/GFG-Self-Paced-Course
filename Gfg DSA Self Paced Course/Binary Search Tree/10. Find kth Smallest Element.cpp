//First approach  :  Any DFS traversal then store it in vector then sort it and print the kth element from start
// Time complexity : O(N) + O(nlogn)
//Space Complexity : O(N)


//Second Approach : Use Inorder Traversal and store it in vector and print the kth element from start, as inorder is always in ascending order.
//Time Complexity : O(N)
//Space Complexity : O(N)

void inorder(Node *root, int &k){

    if(!root) return;

    inorder(root->left,k);
    if(--k==0) res = root->val;
    inorder(root->right,k);

}

int kthSmallest(Node *root, int k)
{
    inorder(root, k);
    return res;
}

// the second approach can be done by using stack too, which can improve the average case space complexity



int kthSmallest(Node *root, int k)
{
    stack<int> = new Linkedlist<>();

    while(true)
    {
        while(root!=NULL)
        {
            s.push(root);
            root = root->left;
        }
        s.pop();
        if(--k == 0) return root->val;

        root = root->right;
    }
}

//Third Approach : Same as Second approach , just maintain the count variable and when count == k , then just print that specific value.
//Morris Traversal can help to optimize it to Space complexity to O(1)