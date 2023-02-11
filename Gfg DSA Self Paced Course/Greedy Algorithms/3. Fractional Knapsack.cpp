//This is the problem in which we are given a table with the weight and value of each pair
// and a knapsack capacity
// we have to determine the maximum capacity which can be filled with the above table information

// Algorithm : 

// 1. Calculate ratio(value / weight) for every item.
// 2. Sort all items in decreasing order of the ratio.
// 3. Initialize : res = 0, curr_cap = given_cap
// 4. Do foll. for every item I in sorted order : 
       
       //a.) Else if (I.weight <= curr_cap)
             {
                curr_cap -= I.weight
                res += I.value
             }
       
       //b.) Else
             { 
                res  += (I.value)*(curr_cap/I.weight);
                return res;
             }

// 5. Return res             


// Time Complexity: O(nlogn) + O(n) , which turns out to be O(nlogn)



#include<bits/stdc++.h>
using namespace std;

bool myCmp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double) a.first/a.second;

    double r2 = (double) b.first/b.second;

    return r1 > r2;
}


double fKnapS(int W, pair<int , int> arr[] , int n)
{
    sort(arr, arr + n, myCmp);

    double res = 0.0;

    for(int i=0; i<n; i++)
    {
        if(arr[i].second <= W)
        {
            res+= arr[i].first;
            W = W - arr[i].second;
        }

        else{

            res+= arr[i].first * ((double) W / arr[i].second);

            break;
        }
    }

    return res;

}