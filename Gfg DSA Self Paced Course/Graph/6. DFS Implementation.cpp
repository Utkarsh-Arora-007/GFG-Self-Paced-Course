// First Version when the Source is given in a fully connected graph.

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;

    cout<<s<<" ";

    for(int u: adj[s])
    {
        if(visited[u] == false)
            DFSRec(adj, u, visited);
    }
}


void DFS(vector<int> adj[], int v, int s)
{
    bool visited[v];
    for(int i=0; i<v; i++)
        visited[i] = false;

    DFSRec(adj,s);    
}



//Second Version, if the graph is disconnected :

void DFSRec(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;

    cout<<s<<" ";
    for(int u: adj[s])
    {
        if(visited[u] == false)
           DFSRec(adj, u, visited);
    }

}


void DFS(vector<int> adj[], int v)
{
    bool visited[v];

    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i] == false)
           DFSRec(adj, i, visited);
    }
}



// If you want to count total number of disconnected graphs, then just modify the last function

int DFS(vector<int> adj[], int v)
{
    bool visited[v];
    int count = 0;

    for(int i=0; i<v; i++)
    {
        visited[i] = false;
    }

    for(int i=0; i<v; i++)
    {
        if(visited[i] == false)
        {
            DFSRec(adj, i, visited);
            count++;
        }
    }

    return count;

}


//Time Complexity : O(V+E)


//Applications of DFS :
// 1. Cycle Detection
// 2. Topological Sorting
// 3. Strongly Connected Components : Kosaraju's Algorithmm which uses 2 DFS traversals and Tarjan's Algorithm which is the optimization and uses onyl 1 DFS traversal.
// 4. Solving Maze and Similar Puzzles and in all Major Backtracking Problems, DFS is used.
// 5. Path Finding
