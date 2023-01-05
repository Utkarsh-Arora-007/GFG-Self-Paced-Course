// Naive Solution

// 1. We divide the array from middle. Use First half for Stack 1 and Second Half for Stack 2.
// 2. Inefficient Use of Space - If we add 5 items to Stack 1, and no items to stack 2, then we cannot add any more items to stack 1 even if we have space in the array.


#include<bits/stdc++.h>
using namespace std;

struct TwoStacks {
    int *arr;
    int cap;
    int top1 , top2;

    TwoStacks(int n)
    {
        cap = n;
        arr = new int[n];
        top1 = n/2 + 1;
        top2 = n/2;
    }

     void push1(int x)
     {
        if(top1 > 0)
        {
            top1--;
            arr[top1] = x;
        }
        else{
            cout<<"Stack Overflow"<<"By element :" <<x<<endl;
            return;
        }
     }

     void push2(int x)
     {
        if(top2 < cap -1)
        {
            top2++;
            arr[top2] = x;

        }

        else{
             cout << "Stack Overflow"
                 << " By element :" << x << endl; 
            return; 
        }
     }


     int pop1()
     {
        if(top1 <= cap/2){
            int x = arr[top1];
            top1++;
            return x;
        }

        else{
            cout<<"Stack Underflow";
            exit(1);
        }
     }

     int pop2()
     {
        if(top2 > = cap/2+1)
        {
            int x - arr[top2];
            top2--;
            return x;
        }
        else{
            cout<<"Stack Underflow";
            exit(1);
        }
     }
};

int main() 
{ 
    TwoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is: " << ts.pop1() << endl; 
    ts.push2(40); 
    cout << "Popped element from stack2 is: " << ts.pop2() << endl; 
    return 0; 
}






// Efficient Solution:

// 1. Begin both stacks from the two corners of the array.
// 2. Now we can insert items in any stack as long as we have space.

#include<bits/stdc++.h>
using namespace std;

struct TwoStacks{
    int *arr;
    int cap;
    int top1, top2;

    TwoStacks(int n)
    {
        cap = n;
        arr = new int[n];
        top1 = -1;
        top2 = cap;
    }

    void push1(int x)
    {
        if(top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }

        else{
            cout<<"Stack Overflow";
            exit(1);
        }

    }


    void push2(int x)
    {
        if(top1 < top2-1)
        {
            top2--;
            arr[top2] = x;
        }

        else{
            cout<<"Stack Overflow";
            exit(1);
        }
    }

    int pop1()
    {
        if(top1 >=0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        else{
            cout<<"Stack Underflow";
            exit(1);
        }
    }

    int pop2()
    {
        if(top2 < cap)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        else{
            cout<<"Stack Underflow";
            exit(1);
        }
    }

};

int main()
{
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7); 
    cout << "Popped element from stack1 is "<<ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is "<< ts.pop2(); 
    return 0;
}

