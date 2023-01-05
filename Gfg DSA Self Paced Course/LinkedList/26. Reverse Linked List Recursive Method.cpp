//Method 1: 

#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
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
    }cout<<endl;
}

Node *recRevL(Node *head)
{
    if(head == NULL || head->next==NULL) return head;
    Node *rest_head = recRevL(head->next);
    Node *rest_tail = head->next;
    Node *rest_tail = head->next;
    head->next = NULL;
    return rest_head;
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    head = recRevL(head);
    printlist(head);
    return 0;
}



//Method 2:

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
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
    }cout<<endl;
}

Node *recRevL(Node *curr, Node *prev)
{
    if(curr == NULL)
       return prev;

    Node *next= curr->next;
    curr->next = prev;
    return recRevL(next, curr);   
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    head = recRevL(head, NULL);
    printlist(head);
    return 0;
}
