//Algorithm : 

// 1. Initialize dist[v] = { INF, INF, -----, INF}
// 2. dist[s] = 0
// 3. create queue, q
// 4. Initialize :  visited[v] = { false, false, ------, false}
// 5. q.push(s), visited[s] = true
// 6. while(q is not empty)
//      {

        //    u = q.pop()
        //    for every adjacent v of u
        //    {
        //        if(visited[v] == false)
        //        {
        //            dist[v] = dist[u] + 1
        //            visited[v] = true
        //            q.push(v)
        //        }
        //    }

//      } 

// 7. Print dist[]



#include<bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int v, int s, int dist[])
{
    bool visited[v];

    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();

        for(int v : adj[u])
        {
            if(visited[v] == false)
            {
                dist[v] = dist[u] + 1;   // In order to ensure that the path traversed is the shortest path , and not from any other path.
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


int main()
{
    int v = 4;
    vector<int> adj[v];

    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);

    int dist[v];

    for(int i=0; i<v; i++)
    {
        dist[i] = INT_MAX;
    }

    dist[0] = 0;

    BFS(adj, v, 0, dist);

    for(int i=0; i<v; i++)
    {
        cout<<dist[i]<<" ";
    }

    return 0;
}


//Time Complexity : O(V+E)