//Priority_Queue using Max-Heap

#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout<<pq.size()<<" ";
    cout<<pq.size()<<" ";
    while(pq.empty() == false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}


//Min-Heap Priority Queue
#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;   //reversing the order of the priority queue 
    pq.push(10);
    pq.push(15);
    pq.push(5);

    cout<<pq.size()<<" ";
    cout<<pq.top()<<" ";
    while(pq.empty() == false)
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}