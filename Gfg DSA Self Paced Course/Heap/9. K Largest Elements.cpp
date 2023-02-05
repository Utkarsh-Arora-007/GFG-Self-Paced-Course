//Naive approach : sort the array and then print the last K elements
//Time Complexity : O(nlogn)

//Better Solution : Use a Max Heap and Remove the First K Elements
//Time Complexity : First for MaxHeap : O(n) then Extract Key k times : O(klogn)
//total : O(n + klogn)


//Efficient Solution : O(k + (n-k)logk)
#include<bits/stdc++.h>
using namespace std;

void firstKElements(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int i=0; i<k; i++)
    {
        minHeap.push(arr[i]);
    }

    for(int i=k; i<n; i++)
    {
        if(minHeap.top() > arr[i])
           continue;

        else{
            minHeap.pop();
            minHeap.push(arr[i]);
        }   
    }

    while(minHeap.empty()==false)
    {
        cout<<minHeap.top()<<" ";
        minHeap.pop();
    }
}

int main()
{
   int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;

	firstKElements(arr,size,k);

	return 0;
}