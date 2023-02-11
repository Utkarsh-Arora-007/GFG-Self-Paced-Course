#include<bits/stdc++.h>
using namespace std;

bool DFSRec(vector<int> adj[], int s, bool visited[], bol recSt[])
{

    visited[s] = true;
    recSt[s] = true;

    for(int u: adj[s])
    {

        //when the node is not visited
        if(visited[u] == false && DFSRec(adj, u, visited, recSt) == true)
        {
            return true;
        }

        // If the node has been previosuly visited
        // but it has to be visited on the same path again.

        else if(recSt[u] == true)
        {
            return true;
        }
    }

    recSt[s] = false;
    return false;
}


// function to detect the cycle in a directed graph.

bool DFS(vector<int> adj[], int v)
{
    bool visited[v];
    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    bool recSt[v];
    for(int i=0; i<v; i++)
    {
        recSt[i] = false;
    }

    for(int i=0; i<v;i++)
    {
        if(visited[i] == false)
        {
            if(DFSRec(adj, i, visited, recSt) == true)
                 return true;
        }
    }

    return false;
}



void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int v = 6;
    vector<int> adj[v];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    if(DFS(adj, v))
       cout<<"Cycle Found";

    else
      cout<<"No Cycle Found";

    
    return 0;   
}