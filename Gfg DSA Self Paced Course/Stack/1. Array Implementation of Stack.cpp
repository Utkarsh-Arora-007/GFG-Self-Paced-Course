#include<bits/stdc++.h>

using namespace std;


struct MyStack
{
    int *arr;
    int cap;
    int top;

    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    void push(int x)
    {
        top++;
        arr[top] = -1;
    }

    int pop()
    {
        int res = arr[top];
        top--;
        return res;
    }

    int peek()
    {
        return arr[top];
    }

    int size()
    {
        return (top+1);
    }

    bool isEmpty()
    {
        return (top == 1);
    }
};

int main()
{
    MyStack s(5);
    cout<<s.pop()<<endl;
    cout<<s.peek()<<endl;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    return 0;
}


//Major Problem with this code
// 1. Does not Handle Overflow and Underflow
// 2. We need to provide capacity initially.No Dynamic resizing.




struct MyStack
{
    vector<int> v;
    void.push(int x)
    {
        v.push_back(x);
    }

    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }

    int size()
    {
        return v.size();

    }

    bool isEmpty()
    {
        return v.empty();
    }

    int peek()
    {
        return v.back();
    }
};