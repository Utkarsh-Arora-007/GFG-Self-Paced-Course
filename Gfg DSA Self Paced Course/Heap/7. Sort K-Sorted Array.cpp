//Naive Solution :  Just sort the array in O(nlogn) time.


//Efficient Solution
#include<bits/stdc++.h>
using namespace std;

int sortK(int arr[] , int n, int k)
{
    priority_queue<int, vector<int>,greater<int> > pq;


    //O(klogk)

    for(int i=0; i<=k; i++)
    {
        pq.push(arr[i]);
    }

    int index = 0;

    //O((n-k)logk)

    for(int i = k+1; i<n ; i++)
    {
        arr[index++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    //O(klogk)

    while(pq.empty() == false) { 

        arr[index++] = pq.pop();
        pq.pop();
    }
}

//Overall Time Complexity is O(klogk) of the above function.
void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
      cout<<arr[i]<<" ";

    cout<<endl;  
}


int main()
{
    int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);

    sortK(arr,n,k);

    cout<<"Following is sorted array"<<endl;
    printArray(arr,n);

    return 0;
}