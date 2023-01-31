//Method 1:
//Take the inorder traversal of the BST and then store it in an array format.
//Then use the 2 Pointer approach to solve the two sum problem.

//Time Complexity : Theta(n)
//Aux Space : Theta(n)



//Method 2 : Using Hashing Technique
//Time and Space Complexity : O(N)

bool isPairSum(Node *root, int sum, unordered_set<int> &s)
{
    if(root == NULL)  return false;

    if(isPairSum(root->left, sum , s) == true)
       return true;

    if(s.find(sum-root->key) != s.end())
       return true;

    else
       s.insert(root->key);

    return isPathBST(root->right, sum, s);         
}