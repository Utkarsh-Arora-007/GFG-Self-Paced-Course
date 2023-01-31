//Number 1:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    for(int x :s)
    {
        cout<<x<<" ";
    }

    set<int, greater<int>> s1;   //used to print the elements of set in decreasing order.
    s1.insert(10);
    s1.insert(5);
    s1.insert(20);

    for(auto it = s1.begin(); it!= s1.end(); it++)
    {
        cout<<(*it)<<" ";  //dereferencing the itreator value.
    }
    cout<<endl;

    return 0;

}




//Number 2:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int, greater<int>> s;  // Decreasing Order
    s.insert(10);
    s.insert(5);
    s.insert(20);

    for(auto it = s.rbegin(); it!= s.rend(); it++)
    {
        //Loop to print thes elements in reverse order.
        cout<<(*it)<<endl;
    }
    cout<<endl;

    auto it = s.find(10);
    if(it == s.end())
       cout<<"Not Found"<<endl;
    else
       cout<<"Found"<<endl;

    s.clear();
    cout<<"Size: "<<s.size()<<endl;

    return 0;

}



//Number 3:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(7);

    if(s.count(10))
    {
        cout<<"Found"<<endl;
    }

    else
      cout<<"Not Found"<<endl;

    s.erase(5);

    for(int x: s)
    {
        cout<<x<<" ";
    }cout<<endl;

     auto it = s.find(7);
     s.erase(it);

     for(int x: s)
     {
        cout<<x<<" ";
     } cout<<endl;

     return 0;
}



//Number 4:


#include<bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    auto it = s.lower_bound(5);
    if(it!= s.end())
         cout<<(*it)<<endl;
    else
        cout<<"Given element is greater than the largest"<<endl;

    it = s.upper_bound(5);
    if(it!=s.end())
        cout<<(*it)<<endl;
    else
         cout<<"Given element is greater than the largest"<<endl;


    return 0;                  
}

