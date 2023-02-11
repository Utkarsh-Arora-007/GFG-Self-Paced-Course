// Topological Sorting using Kahn's Based Algorithm

// 1. store the indegree of every index
// 2. create a queue q
// 3. Add all 0 indegree vertices to the q
// 4. while(q is not empty)

    //   {
    //     a.) u = q.pop();
    //     b.) Print u
    //     c.) For every adjacent v of u
    //          i.) Reduce the indegree of v by 1
    //          ii.) If the indegree of v becomes 0, then add v to the q.

    //   }



//Code Implementation :

#include<bits/stdc++.h>
using namespace std;
void topologicalSort(vector<int> adj[], int V)
{
    vector<int> in_degree(V,0);

    for(int u = 0; u < V; i++)
    {
        for(int x: adj[u])
            in_degree[x]++;
    }


    queue<int> q;

    for(int i=0; i<V; i++)
    {
        if(in_degree[i]==0)
           q.push(i);
    }

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        cout<<u<<" ";

        for(int x: adj[u])
            if(--in_degree[x] ==0)
               q.push(x);

    }
}


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);

    cout<<"Following is the Topological Sort :\n";
    topologicalSort(adj,V);

    return 0;
}

// Topological Sorting Situation : When we are given a directed acyclic graph, and the vertices represent the Jobs and Edges Represent the Dependencies.
// We need to print the finishing order of the jobs, so that the dependencies are followed. 
    