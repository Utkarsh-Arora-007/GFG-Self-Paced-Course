//Huffman Coding is the lossless compression technique.

//Variable Length Huffman Coding : 
//   1.) Greedy Idea : The Most Frequent character has smallest code.
//   2.) Prefix Requirement for decompression : No Code should be Prefix of any order , means the code must be prefix-free coding



//Huffman Algorithm : 

// 1. Build a Binary Tree :
//      * Every input character is a leaf.
//      * Every left child edge is labelled as 0 and right edge as 1
//      * Every root to leaf path represents huffman code of the leaf.


// 2. Traverse the binary tree and print the codes.



//Full Algorithm :

// 1. Create leaf nodes and build a Min-Heap h of all the leaves initially.

// 2. while ( h.size() > 1 )
//      a.) left = h.extractMin();
//      b.) right = h.extractMin();
//      c.) Create a new tree node with
//          * character as $
//          * Frequency as left.freq + right.freq
//          * Left and right children as left and right respectively.

//      d.) Insert the new Ndoe into h

// 3. The only node left in h is our required Binary tree.


void printCodes(root, str="")
{
    if(root == NULL)
    {
        return;
    }

    if(root.ch!='$')
       print(root.ch + " " + str)
       return


    printCodes(root.left, str+"0")
    printCodes(root.right, str+"1")   

}

//Printing Huffman Codes from the Built Binary Tree

//Output : 
f 0
b 10
a 1100
b 1101
e 111





//Full Implementation:

#include<bits/stdc++.h>
using namespace std;

//A Huffman Tree Node
struct Node{

// One of the input characters
    char data;

// Frequency of the character
    unsigned freq;

    // Left and right child

    Node *left, *right;

    Node(char data, unsigned freq, Node *l = NULL, Node *r = NULL)
    {
        this->left = l;
        this->right = r;
        this->data = data;
        this->freq = freq;
    }


};


//For comparison of two heap nodes(neede in min heap)

struct compare {

    bool operator()(Node *l, Node *r)
    {
        return (l->freq > r->freq);
    }
};


//Prints Huffman codes from the root of Huffman Tree.

void printCodes(struct Node*root, string str)
{
    if(!root)
        return;

    if(root->data !='$')
       cout<<root->data<<":"<<str<<"\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");       
}

//The main function that builds a Huffman Tree and
//print codes by traversing the built Huffman Tree

void printHCodes(char arr[] , int freq[], int size)
{
    //Create a min heap & inserts all characters of data[]

    priority_queue<Node *, vector<Node*> , compare> h;

    for(int i=0; i<size; i++)
    {
        h.push(new Node(arr[i], freq[i]));
    }

    //Iterate while size of heap doesn't become 1

    while(h.size() > 1)
    {

        //Extract the 2 minimum freq items from the min heap
        Node *l = h.top();
        h.pop();

        Node*r = h.top();
        h.pop();




        // Create a new internal node with
		// frequency equal to the sum of the
		// two nodes frequencies. Make the
		// two extracted node as left and right children
		// of this new node. Add this node
		// to the min heap '$' is a special value
		// for internal nodes, not used


        Node *top = new Node('$', l->freq + r->freq, l, r);

		h.push(top);

    }

    // Print Huffman codes using
	// the Huffman tree built above
	printCodes(h.top(), "");
}


// Driver Code
int main()
{

	char arr[] = { 'a', 'd', 'e', 'f' };
	int freq[] = { 30, 40, 80, 60 };

	int size = sizeof(arr) / sizeof(arr[0]);

	printHcodes(arr, freq, size);

	return 0;
}