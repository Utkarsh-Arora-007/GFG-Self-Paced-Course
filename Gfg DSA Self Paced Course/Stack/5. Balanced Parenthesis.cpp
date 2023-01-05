#include<bits/stdc++.h>
using namespace std;

bool isBalanced(string str)
{
    stack<char> s;

    for(char x : str)
    {
        if(x=='(' || x=='{' || x=='[')
           s.push(x);

        else
        {
            if(s.empty() == false)
              return false;

            if(matching(s.top(),x) == false)
              return false;

            else  
              s.pop();    

        }   
    }

    return (s.empty() == true);

}


//Time and Space Complexity : O(n)
