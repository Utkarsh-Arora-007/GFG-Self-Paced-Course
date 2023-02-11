//Detect Cycle in a Directed Graph (Part 2)
// Based on Kahn's Algorithm

// 1. Store indegree of every vertex
// 2. Create a queue, q
// 3. Add all 0 indegree vertices to the q
// 4. count = 0
// 5. while(q is not empty)
    // {
    //      a.) u = q.pop()
    //      b.) For every adjacent v of u:
    //          i.) Reduce indegree of v by 1
    //          ii.) If indegree of v becomes 0, 
    //               push v to the q
         
    //      c.) count++;             
    // }

// 6. return (count!=V)

// Time Complexity : O(V+E)

// Pro TIP : Just see there that if there is not vertex with indegree 0, and there is still some vertices left, then they form a Cycle, otherwise not.


#include<bits/stdc++.h>
using namespace std;

void topologicalSort(vector<int> adj[], int V)
{
    vector<int> in_degree(V,0);

    for(int u = 0; u<V; u++)
    {
        //count pf elements in the adjacency list of each respective element
        for(int x: adj[u])
           in_degree[x]++;
    }

    queue<int> q;

    for(int i=0; i < V; i++)
    {
        if(in_degree[i] == 0)
             q.push(i);
    }


    int count = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int x: adj[u])
            if(--in_degree[x] == 0)
                q.push(x);

        count++;        
    }

    //Check if the final count is equal to the total number of vertices or not.
    
    if(count!=V)
    {
        cout<<"Yes, there exists a cycle in the graph\n";
    }

    else{
        cout<<"There exists no cycle in the graph\n";
    }

}

// Creation of Adjacency List
void addEdge(vector<int> adj[], int u, int v)
{
     adj[u].push_back(v);
}

int main()
{
    int V = 5;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 4, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    topologicalSort(adj, V);

    return 0;
}