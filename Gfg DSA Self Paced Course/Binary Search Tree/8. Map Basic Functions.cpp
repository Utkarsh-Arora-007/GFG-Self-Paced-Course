//Number 1:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    m.insert({10,200});
    m[5] = 100;
    //we can use this to update the value as well, but in case we use [] this with a value which is not present, then it adds a new entry in the map and does not throw error.
    m.insert({3,300});
    //Inserts the { key, value } pair in the map.

    for(auto &x : m)
    {
        cout<<x.first<<" "<<x.second<<endl;

        //x.first prints the key and x.second prints the value. 
    }

    cout<<"Size: "<<m.size()<<endl;

    m.at(10) = 300;
    //It updates the value with the new value if already present, otherwise throw runtime error.
    
    return 0;
}



//Number 2:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> m;
    m.insert({10,200});
    m[5] = 100;
    m.insert({3,300});

    for(auto it = m.begin(); it!=m.end(); it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    m.clear();
    cout<<"Size: "<<m.size()<<endl;
    cout<<"Empty: "<<(m.empty()? "Yes":"No")<<endl;

    return 0;
}


//Number 3:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int , string> m;

    m.insert({5,"gfg"});
    m.insert({2,"ide"});
    m.insert({1,"practice"});

    if(m.find(5) == m.end())
    {
        cout<<"Not Found";
    }

    //the above loop is responsible for finding the value which is written in find() function, if the value is not available then it returns m.end()
    //The find() function also gives the iterator which is pointing to the address of the value.

    else
      cout<<"Found";
      cout<<endl;

    if(m.count(2) == 0)    //the count() function is mostly same as find() function but it does not return the the itreator to the address of the value, it just return whether the value is present or not.
       cout<<"Not Found";
    else
       cout<<"Found";
    
    cout<<endl;

    auto it = m.lower_bound(7); // it displays value equal to 7 if present or greater than 7, if anything not present, then m.end()
    if(it!=m.end())
      cout<<(*it).first<<" ";
    else
      cout<<"No Equal or Greater Value";

    return 0;

}


//Number 4:

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int ,string> m;
    m.insert({5,"gfg"});
    m.insert({2,"ide"});
    m.insert({1,"practice"});

    auto it = m.upper_bound(2);  // it will print the key just next to 2, in case of increasing order it will show next high value and in case of decreasing order, it will just print the key just next to it.
    if(it!=m.end())
       cout<<(*it).first<<endl;

    else
       cout<<"Greater Value"<<endl;

    m.erase(5);
    cout<<"Size: "<<m.size()<<endl;

    m.erase(m.find(2),m.end());
    cout<<"Size: "<<m.size()<<endl;

    return 0;      
}