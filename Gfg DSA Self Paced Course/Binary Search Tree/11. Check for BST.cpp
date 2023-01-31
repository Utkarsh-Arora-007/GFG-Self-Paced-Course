// Method 1  : Basic but incorrect approach
//Check for the left node is smaller than the right node of the subtree.


//Method 2 : Correct but Inefficient
//For every node,
//1. Find maximum in left subtree.
//2. Find minimum in right subtree.
//3. Check if the current node is greater than the maximum and smaller than the minimum.

//ex: if there is tree and 20 is the root, 8 is the max left element and 18 is the minimum right element then , in order to be a BST, then 20 must be greater than 8 and smaller than 18, which in this case is not true, so print false. 




//Method 3: Simple and Efficient (Range - Based Solution)

//1. Pass a range for every node.
//2. For root, range is -infinity to +infinity.
//3. for left child change the upper bound, as the node's value.
//4. for right child changne the lower bound in range, we change the lower bound as the node's value.

bool isBST(Node *root, int min, int max)
{
    if(root == NULL)
    return true;

    return (root->data > min && root->data < max && inBST(root->left, min, root->data) && inBST(root->right, root->data, max));
}



//Method 4 : Most Efficient Solution
// It is based on the fact that the Inorder of the BST is compulsory in sorted order.
// if the inorder of that BST is not sorted then , it is not a BST.
//Time Complexity : O(N) and Space Complexity : O(h) 
int Prev = INT_MIN;
bool isBST(Node *root)
{
    if(root == NULL) return true;
    if(isBST(root->left) == false) return false;
    if(root->key <= prev) return false;
    prev = root->key;
    return isBST(root->right);
}

