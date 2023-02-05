//Binary Heap is a complete Binary Tree (Stored as an array)

//Left-Node(i) = 2i+1
//Right-Node(i) = 2i+2
//to find parent(i) of any node index = floor(i-1 / 2)


//Heaps are of Mainly 2 Types : Min Heap and Max Heap

//Min Heap - Complete Binary Tree and Every Node has smaller value than its descendents.



 //Basic Heap Implementation :

 #include<bits/stdc++.h>
 using namespace std;

 class MinHeap{

    int *arr;
    int size;
    int capacity;

    public:

    MinHeap(int c){
        size = 0;
        capacity = c;
        arr = new int[c];
    }

    int left(int i) { return (2*1+1); }
    int right(int i) { return (2*i+2); }
    int parent(int i) { return (i-1)/2; }

 };

 int main()
 {
    MinHeap h(11);
    return 0;
 }