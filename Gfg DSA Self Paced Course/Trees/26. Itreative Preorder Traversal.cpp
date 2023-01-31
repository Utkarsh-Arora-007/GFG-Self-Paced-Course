//Time Complexity:O(N)
//Space Complexity : O(h)

void itreativePreOrder(Node *root)
{
    if(root == NULL)
    return;

    stack<Node *> st;
    st.push(root);
    while(st.empty() == false)
    {
        Node *curr = st.top();
        cout<<(curr->key)<<" ";
        st.pop();
        if(curr->right!=NULL)
        st.push(curr->right);
        if(curr->left!=NULL)
        st.push(curr->left);

    }
}



//Space Optimized Approach : Only stores the right children

void itreativePreorder(Node *root)
{
    if(root == NULL)
    return;
    stack<Node *> st;
    Node *curr = root;
    while(curr!=NULL || st.empty() == false)
    {
        while(curr!=NULL)
        {
            cout<<(curr->key)<<" ";
            if(curr->right!=NULL)
            {
                st.push(curr->right);
            }

            curr = curr->left;
        }

        if(st.empty() == false) { curr = st.top(); st.pop(); }
    }
}