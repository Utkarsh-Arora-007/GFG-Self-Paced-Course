//We will use stack based solution in which we will traverse left left left till the end and
//then we will pop out the nodes one by one and check their right subtree nodes, if null then pop out second item then again check for right subtree nodes and print them and
//this porcess goes on till the stack is empty

void itreativeInorder(Node *root)
{
    stack<Node *> st;
    Node *curr = root;
    while(curr!=NULL || st.isEmpty()==false)
    {
        while(curr!=NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();
        cout<<(curr->key)<<" ";
        curr = curr->right;
    }
}