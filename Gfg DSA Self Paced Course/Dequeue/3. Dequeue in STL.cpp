//Example 1(push, front, back)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq = {10,20,30};
    dq.push_front(5);
    dq.push_back(50);

    for(auto x:dq)
    {
        cout<<x<<" ";
    }
    cout<<dq.front()<<" "<<dq.back();

    return 0;
}


//Example 2(begin, insert, pop and size)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq = {10,20,30};
    
    auto it = dq.begin();
    it++;

    dq.insert(it,20);

    dq.pop_front();
    dq.pop_back();
    cout<<dq.size();

    return 0;
}



//Example 3(insert and erase)

#include<bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq = {10,20,5,30};

    auto it = dq.begin();

//inserts from the front
    it = dq.insert(it,7);

    it = dq.insert(it,2,3);
    
   //Erases from front

   it = dq.erase(it+1);

    cout<<(*it)<<endl;

    for(int i=0; i<dq.size(); i++)
       cout<<dq[i]<<" ";

    return 0;   
}