//Naive Approach
//Time Complexity : O(nk)
//Space Complexity : O(n)

#include<bits/stdc++.h>
using namespace std;

void printKClosest(int arr[], int n, int k, int x)
{
    bool visited[n] = {false};

    for(int i=0; i<k; i++)
    {
        int min_diff = INT_MAX;
        int min_diff_idx;

        for(int j=0; j<n; j++)
        {
            if(visited[j] == false && abs(arr[j]-x)<=min_diff)
            {
                min_diff = abs(arr[j]-x);
                min_diff_idx = j;
            }
        }

        cout<<arr[min_diff_idx]<<" ";
        visited[min_diff_idx] = true;
    }
}

int main()
{
    int arr[] = { 10, 30, 5, 40, 38, 80, 70 };
    int size = sizeof(arr)/sizeof(arr[0]);


    int x = 35; int k = 3;

    printKClosest(arr, size, k, x);

    return 0; 
}





//Efficient Solution : Maintain a Max - Heap and Pop out the top element until the heap size is equal to k

// Time Complexity :  O(nlogk)

#include<bits/stdc++.h>
using namespace std;

void printkClosest(int arr[], int n, int k, int x)
{
    priority_queue<pair<int, int> > pq;
    for (int i=0; i<k; i++)
       pq.push({ abs(arr[i]-x),i });

    for(int i= k; i<n; i++)
    {
        int diff = abs(arr[i] - x);
        if(pq.top().first > diff){

            pq.pop();
            pq.push({ diff, i});
        }
    }

    while(pq.empty() == false)
    {
        //second value stores the index of the actual input array
        cout<<arr[pq.top().second]<<" ";
        pq.pop();
    }   

}


int main()
{
    int arr[] = { 10, 30, 5, 40, 38, 80, 70 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int x = 35; int k = 3;
    printkClosest(arr,size,k,n);

    return 0;
}
