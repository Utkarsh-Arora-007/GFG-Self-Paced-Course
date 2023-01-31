void vTraversal(Node *root)
{
    map<int , vector<int>> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while(q.empty() == false)
    {
        auto p = q.front();
        Node *curr = p.first;
        int hd = p.second;

        mp[hd] = p.second;
        q.pop();
        if(curr->left !=NULL)
            q.push({curr->left, hd-1});
        if(curr->right!=NULL)
           q.push({curr->right, hd+1});


    //Print the map contents line by line           

    for(auto: p)
    {
        vector<int> v = p.second;
        for(int x : v)
          cout<<x<<" ";
        cout<<endl;  
    }

    }
}