//here ceiling of left side is the smallest number on the left side which is just greatest from that given number:
//If no such element is found, then print -1.

//Pseudo Code

//Naive Solution :  Time Complexity: O(N^2)  and Space Complexity : O(1)

void printCeiling(int arr[], int n)
{
    cout<<-1;
    //always -1 for the first value in the array, coz there is the first element of the array.

    for(int i=1; i<n;i++)
    {
        int diff = INT_MAX;
        for(j=0; j<i;j++)
        {
            if(arr[j] >= arr[i])
                diff = min(diff, arr[j] - arr[i]);    
        }

        if(diff = INT_MAX)
           cout<<-1;
        else
           cout<<arr[i]+diff;   
    }

}




//Efficient Solution
//Time Complexity : O(nlogn)
// this can be achieved by using self-balancing binary search tree (in C++ we will use Set)

void printceiling(int arr[], int n)
{
    cout<<-1; //for the first element always

    // 1. create a self balancing BST (Set in C++)
    // 2. Insert arr[0] into s
3. for(int i = 1; i<n; i++)
    {
        if(s contains a celing of arr[i])
            print the Ceiling

        else
             print -1;

    }  insert arr[i] into s
}
