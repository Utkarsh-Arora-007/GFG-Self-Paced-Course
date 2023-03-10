//Naive Solution
// O(n^2) Solution
#include <bits/stdc++.h>
using namespace std;

void nextGreater(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j;
        for(j=i+1; j<n;j++)
        {
            if(arr[j] > arr[i])
            {
                cout<<arr[j]<<" ";
                break;
            }
        }

        if(j==n)
          cout<<-1<<" ";
    }
}

int main()
{
    int arr[] = {5,15,10,8,6,12,9,18};
    int n=8;
    nextGreater(arr,n);
    return 0;
}




//Efficient Solution : O(n) Time and Space Complexity

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterNew(int arr[], int n)
{
    vector<int> v;
    stack<int> s;

    s.push(arr[n-1]); v.push_back(-1);
    for(int i= n-2; i>=0; i--)
    {
        while(s.empty()==false && s.top()<=arr[i])
           s.pop();

        int next_greater = s.empty() ? -1:s.top();
        v.push_back(next_greater);
        s.push(arr[i]);   
    }

    reverse(v.begin(), v.end());
    return v;
}


int main()
{
    int arr[] = { 5,15,10,8,6,12,9,18};
    int n = 8;
    for(int x: nextGreaterNew(arr,n)){
        cout<<x<<" ";
    }

    return 0;
}