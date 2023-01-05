//Naive Solution
int firstPetrolPump(int petrol[], int dist[], int n)
{
    for(int start =0; start<n; start++)
    {
        int curr_petrol = 0;
        int end = start;
        while(true)
        {
            curr_petrol+=(petrol[end] - dist[end]);
            if(curr_petrol < 0)
              break;
            end = (end+1)%n;
            if(end == start)
            return (start + 1);  
        }
    }

    return -1;
}




//Efficint Solution
//If curr_petrol becomes negative at pi, then none of the petrol pumps from p0 to pi can be can be correct solution
//p0, p1, ..... , p(i),p(i+1),....p(n-1)

// Let p(i) be the first petrol pump where current petrol pump becomes negative, then

// curr_petrol = Sigma [ j=0 to j=i ] (petrol[j] - dist[j])


#include<bits/stdc++.h>
using namespace std;

// A petrol pump has petrol and distance to next petrol pump
class petrolPump{

    public:
    int petrol;
    int distance;

};
// The function returns starting point if there is a possible solution,
// otherwise returns -1

int printTour(petrolPump arr[], int n)
{
    int start = 0;
    int end = 1;

    int curr_petrol = arr[start].petrol - arr[start].distance;
     /* Run a loop while all petrol pumps are not visited.
    And we have reached first petrol pump again with 0 or more petrol */
    while(end!=start || curr_petrol<0)
    {
        // If current amount of petrol in truck becomes less than 0, then
        // remove the starting petrol pump from tour
        while(curr_petrol < 0 || start!=end)
        {
             // Remove starting petrol pump. Change start
             curr_petrol-= arr[start].petrol - arr[start].distance;
             start = (start+1) % n;


            // If 0 is being considered as start again, then there is no
            // possible solution

            if(start == 0)
            return -1;
        }

        //Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1) % n;
    }

    //Return starting point
    return start;
}

int main(){

    petrolPump arr[] = {{6,4},{3,6},{7,3}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr,n);

    (start == -1)? cout<<"No Solution" : cout<<"Start ="<<start;
    
    return 0;
}