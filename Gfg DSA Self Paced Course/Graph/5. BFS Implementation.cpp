//First Version : Given an undirected graph and a source vertex 's' print BFS from the given source

void BFS(vector<int> adj[], int v, int s)
{
    bool visited[v+1];

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

        cout<<u<<" ";

        for(int v: adj[u])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}




//Second Version :  The Source is not Given and Graph my be Disconnected

void BFS(vector<int> adj, int v, int s, bool visited[])
{
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(q.empty() == false)
    {
        int u = q.front();
        q.pop();
        cout<<u<<" ";
        for(int v: adj[u])
        {
            if(visited[v] == false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}


void BFSDisconnected(vector<int> adj[], int v)
{
    bool visited[v+1];

    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i] == false)
            BFS(adj, i, visited);
    }
}





//TIP : for counting Islands Problem, just make small changes in the code, and you are good to go.

int BFSDis(vector<int> adj[], int v)
{
    bool visited[v+1];

    int count = 0;

    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<v; i++)
    {
        BFS(adj, i, visited);
        count++;
    }

    return count;
}



//Applications of BFS:

// 1. Shortest path in unweighted graph.
// 2. Crawlers in Search Engines
// 3. Peer to Peer Networks
// 4. Social Networking Search
// 5. in Garbage Collection (Cheney's Algorithm)
// 6. Cycle Detection
// 7. Ford Fulkerson Algorithm : It is a Maximum-Flow Algorithm and BFS gives better time complexity
// 8. Broadcasting
// Dijstra's Algorithm is based on BFS and Prim's Algorithm for Minimum Spanning Trees is based on BFS.