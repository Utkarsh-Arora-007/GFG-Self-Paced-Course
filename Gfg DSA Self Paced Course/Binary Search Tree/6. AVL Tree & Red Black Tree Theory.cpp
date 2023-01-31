//AVL Tree 

//Worst case of height in AVL Tree will be :
// h < c*log(n+2) + b
// where , c= 1.44 and b = -1.327
//Which makes a it a still very balanced BST Type among all others.
//It is very strict in terms of balancing the BST and this leads to more frequent re-structuring of the Tree.


//Balanced Factor : |lh - rh|  (Calculated for every node)
// Balanced Factor <= 1




//Red-Black Tree

//1. Every Node is either Red or Black
//2. Root is always black.
//3. No two Consecutive Reds.
//4. Number of black nodes from every node of its descendents leaves should be same.

//No. of nodes on the path from a node to its farthest descendent leaf should 
//not be more than twice than the no. of nodes on the path of its closest descendent leaf.

//That's why it is less strict than AVL Trees in terms of re-structuring.




//Applications of BST:

// 1. To maintain sorted stream of data (Or sorted set of data)
// 2. To Implement doubly ended priority queue.
// 3. To solve problems like : 
      // 1. Count Smaller/ Greater in a stream.
      // 2. Floor/ceiling/greater/smaller in a stream.




//SET in C++ STL:

// find() function in set gives the itreator to the element if the target element is present.
// count() function will tell only whether the target element is present or not present.
// clear() function clears all the elements present in the set.
// erase() function takes the element value and deletes that specific element only.     


