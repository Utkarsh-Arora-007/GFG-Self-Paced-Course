//Example 1(push, front, back, pop)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);


    cout<< q.front()<<" "<<q.back()<<endl;

    q.pop();

    cout<< q.front()<<" "<< q.back() <<endl;

    return 0;
}



//Example 2(push, front, back, pop, empty)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    while(q.empty() == false)
    {
        cout<<q.front()<<" "<<q.back()<<endl;
        q.pop();
    }

    return 0;
}




//Example 3(size)
#include<bits/stdc++.h>
using namespace std;

int main()
{
    queue <int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    cout<< q.size();

    return 0;
}