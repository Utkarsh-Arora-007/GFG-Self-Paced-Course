//Naive Approach
//traverse with any approach and then sort it then accordingly find the wrong voilation points which in the tree with the help of sorted Traversal.
//Time Complexity : O(N) + O(nlogn)
//Space Complexity : O(N)


//Efficient Approachs
//Time and Space Complexity : O(N)

class Solution{

    private :

    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

    private:
       
       void inorder(TreeNode *root)
       {
        if(root == NULL)
           return;

        inorder(root->left);

        if(prev!=NULL && (root->val < prev->val))
        {
            if(first == NULL)
            {
                first = prev;
                middle = root;
            }

            else
                last = root;
        }   

        prev = root;
        inorder(root->right);
       }


    public:
       void recoverTree(TreeNode *root)
       {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->val, last->val);
        else if(first && middle) swap(first->val, middle->val);
       }   
};