// I/P : { (3,8) , (2,4) , (1,3) , (10,11) }
// O/P : 3
// First Element of each pair is the start time and the second element is the End-Time.


//Naive Approach :
// Consider Every Activity as the first activity and then use the recursive solution to find the total number of actitvites which can be
//performaed by the machine, then find the maximum of all the answers you get and output that answer.



//Efficient Solution : Greedy Approach 
//Algorithm for the Problem:

//Time Complexity: O(nlogn)

// 1. Sort according to finish time : 
 { (1,3) , (2,4) , (3,8) , (10,11) }

// 2. Initialize Solution as First Activity , matlab Pick the First element of the optimized as the first sorted pair after sorting
// Coz there is the maximum chance that the it will fit in the most of the solutions with having the least end time.

// 3. Do following for remaining activities :
      // a.) If current activity overlaps with the last picked activity in the solution, ignore the current activity
      // b.) Else add the current activity to the Solution.


#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    return (a.second < b.second);
}

int maxActivities(pair <int, int> arr[] , int n)
{
    sort(arr, arr+n, myCmp);

    int prev = 0;
    int res = 1;

    for(int curr = 1; curr < n; curr++)
    {
        if(arr[curr].first >= arr[prev].second)
        {
            res++;

            prev = curr;
        }
    }

    return res;
}


int main()
{
    pair<int, int> arr[] = { make_pair(12, 25), make_pair(10, 20), make_pair(20, 30) };

    int n = 3;

    cout<<maxActivities(arr,n);

    return 0;
}

