//Naive Solution
//1. Find the last Node reference/pointer by doing a traversal.
//2. Traverse the linked List again. For every odd node, Insert it after the last node and make the newly inserted node as the last node.


//Efficient Solution

//We maintain 4 variables
// es-> Reference/Pointer to start of the even sublist.
//ee->  Reference/ Pointer to end of the even sublist.
//os-> Reference / Pointer to start of the odd sublist.
//oe-> Reference / Pointer to the end of the odd sublist.

//All of the above are initialized as null/none.

//while traversing
//      a.) If current node is even, we insert it after ee and update ee. Also update es if this is the first node.
//      b.) Similar to (a) for odd nodes.
//After the loop , connect the two lists.



#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node * curr = head;
    while(curr!= NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}

Node *segregate(Node *head)
{
    Node *eS = NULL , *eE = NULL , *oS = NULL , *oE = NULL;
    for(Node *curr = head; curr!= NULL; curr = curr->next)
    {
        int x = curr->data;
        if(x%2==0){
            if(eS == NULL){
                eS = curr;
                eE = eS;
            }
            else{
                eE->next = curr;
                eE = eE->next;
            }
        }

        else{
            if(oS == NULL)
            {
                oS = curr;
                oE = oS;
            } else { 
                oE->next = curr;
                oE = oE->next;
            }
        }
    }
    if(oS == NULL || eS == NULL)
    {
        return head;
    }
    eE->next = oS;
    oE->next = NULL;
    return eS;
}

int main()
{
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next=new Node(5);
	head->next->next->next->next->next->next=new Node(4);
	printlist(head);
	head=segregate(head);
	printlist(head);
	return 0;
}
