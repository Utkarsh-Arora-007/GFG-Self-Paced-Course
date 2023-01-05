#include<bits/stdc++.h>
using namespace std;


//Theta 1 operation
//Tail pointer can also be used in place of a pointer if we maintain a tail pointer,
// just simply delete it and you are good to go.


struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int d)
    {
        data =d;
        prev = NULL;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

Node *delLast(Node *head)
{
    if(head==NULL)
      return NULL;

    if(head->next == NULL)
    {
        delete head;
        return NULL;
    }  

    Node *curr = head;
    while(curr->next!=NULL)
       curr = curr->next;

    curr->prev->next = NULL;
    delete curr;
    return head;   
}

int main()
{
    Node *head = new Node(10);
    Node *temp1 = new Node(20);
    Node *temp2 = new Node(30);
    head->next = temp1;
    temp1->prev = head;
    temp1->next = temp2;
    temp2->prev = temp1;
    head = delLast(head);
    printlist(head);
    return 0;
}

