//Time Complexity : O(nlogn)
//Space Complexity : O(1)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int cost[n] = { 1,12,5,111,200 };
    int sum = 10;

    int res = 0;
    sort(cost, cost+n);

    for(int i=0; i<n; i++)
    {
        if(cost[i]<=sum)
        {
            sum-=cost[i];
            res++;
        }
        else{
            break;
        }
    }

    cout<<res;
    return 0;
}


//Efficient Solution
//Use Min Heap


//initially, sum = 10, res = 0
//Since top is smaller than sum , pop it : sum = 9, res = 1
//since top is smaller than sum, pop it : sum = 4, res = 2
//Now the top is not smaller than sum, return res.

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    int cost[n] = { 1, 12, 5, 111, 200 };
    int sum = 10;

    priority_queue<int, vector<int>, greater<int>> pq;

    int res = 0;

    for(int i=0; i<n; i++)
    {
        pq.push(cost[i]);
    }

    for(int i=0; i<n; i++)
    {
        if(pq.top()<=sum)
        {
            sum-= pq.top();
            pq.pop();
            res++;
        }
      else{
            break;
        }
    }

    cout<<res;
    return 0;

}