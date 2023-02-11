// We will use an array of vectors in order to represent the adjacency list in C++

#include<bits/stdc++.h>
using namespace std;

class Graph{

    int V;
    list<int> *l;

    //In case We have a Weighted Graph then, we will use pair<int, int> which will store the target vertex and weight of the edge.

    public:
      Graph(int v)
      {
        this->V = v;
        l = new list<int>[V];
      }

      void addEdge(int x, int y)
      {
        l[x].push_back(y);
        l[y].push_back(x);
      }

      void printAdjList()
      {

        //Iterate over all the vertices
        for(int i=0; i<V;i++)
        {
            cout<<"Vertex "<<i<<"->";
            for(int nbr: l[i])
            {
                cout<<nbr<<",";
            }
            cout<<endl;
        }
      }
};


int main()
{
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);
    g.printAdjList();


    return 0;
}


