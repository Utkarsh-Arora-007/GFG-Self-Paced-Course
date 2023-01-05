//First Method (For Positives Only)
//Approach: Use Stack and Use Min Variable
//If you push Greater elements that's Fine but If you push smaller element than the top most item in Stack then, you need to update the min element and keep track of previous minimum as well.


#include<bits/stdc++.h>
using namespace std;

struct MyStack {

    stack<int> s;
    int min;

    void push(int x){
        if(s.empty()){
            min = x;
            s.push(x);
        }

        else if(x<= min){
            s.push(x-min);
            min = x;
        }

        else{
            s.push(x);
        }
    }

    int pop() {

        int t = s.top();
        s.pop();

        if(t<=0){
            int res = min;
            min = min-t;
            return res;
        }
        else{
            return t;
        }
    }

    int top() {
        int t = s.top();
        return ((t<=0) ? min : t);
    }

    int getMin() {
        return min;
    }
};

int main()
{
    MyStack s;
    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();

    cout<<" Minimum Element from Stack: "<<s.getMin();

    return 0;
}



//Second Method (Handling Negatives)
//If the new element is Greater than the current minimum element then we will use the formula = 2 * x - min and x will be new minimum

#include <bits/stdc++.h>
using namespace std;

struct MyStack {

    stack<int> s;
    int min;
    
    void push(int x){

        if(s.empty() ){
            min =x;
            s.push(x);
        }

        else if(x<=min){
            s.push(2*x - min);
            min = x;
        }
        else{
            s.push(x);
        }
    } 

    int pop() {

        int t = s.top();
        s.pop();

        if(t <= min){
            int res = min;
            min = 2* min -t;
            return res;
        }
        else{
            return t;
        }
    }


    int top(){
        int t = s.top();
        return ((t<=min) ? min : t);
    }

    int getMin(){
        return min;
    }


};


int main()
{
    MyStack s;

    s.push(4);
    s.push(5);
    s.push(8);
    s.push(1);
    s.pop();

    cout<<" Minimum Element from Stack: "<<s.getMin();

    return 0;
}




