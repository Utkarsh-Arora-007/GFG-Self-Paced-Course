// It is a simple DFS Traversal just that we are passing an additional parameter PARENT, as if there is a vertex which is already visited and it is not a parent vertex , then return true.
// Time Complexity: O(V+E)


#include<bits/stdc++.h>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;

    for(int u: adj[s])
    {
        if(visited[u] == false)
        {
            if(DFSRec(adj, u, visited, s) == false)
                return true;     
        }

        else if(u!=parent)
        {
            return true;
        }
    }
    return false;
}

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, -1) == true)
                 return true;
        }
    }

    return false;
}


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main()
{
    int v = 6;
    vector<int> adj[v];

    addEdge(Adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);

    if(DFS(adj, v))
        cout<<"Cycle Found";

    else
        cout<<"Cycle not Found";    

    return 0;    
}