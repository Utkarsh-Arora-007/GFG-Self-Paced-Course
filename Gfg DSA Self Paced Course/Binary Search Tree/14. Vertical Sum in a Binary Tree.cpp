void vSumR(Node *root, int hd, map<int , int> &mp)
{
    if(root == NULL) return;
    vSumR(root->left, hd-1, mp);
    mp[hd]+=root->data;
    vSumR(root->right, hd+1, mp);
}

void vSum(Node *root)
{
    vector<int> v;
    map<int, int> mp;
    vSumR(root, o, mp);
    for(auto x:mp)
    {
        v.push_back(x.second);
    }

    return v;
}


// Time Complexity : O(nlog(hd) + hd)
// approximate : O(nlog (hd))
//where hd = total no. of possible horizontal distances. 