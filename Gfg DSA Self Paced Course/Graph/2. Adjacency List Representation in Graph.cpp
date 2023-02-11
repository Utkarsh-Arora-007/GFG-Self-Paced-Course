//An Arrayy of lists where lists are most popularly represented as :
//a. Dynamic Sized Arrays  (mostly it is used in the implementation of Adjacency List)
//b. Linked Lists


//Adjacency List : Space : Theta(V+E)
//Undirected Graph : V + 2*E
//Directed Graph : V + E

//Operations: 1. Check if there is an edge from u to v : O(v)
//2. Find all adjacent of u : Theta(degree(u))
//3. Find degree of u : Theta(1)
//4. Add an Edge : Theta(1)
//5. Remove an Edge : O(v)