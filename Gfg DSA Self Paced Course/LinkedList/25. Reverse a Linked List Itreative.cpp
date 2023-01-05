//Naive Solution

#include<bits/stdc++.h>
using namespace std;

struct Node
{
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
    Node *curr = head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}

Node *revList(Node *head)
{
    vector<int> arr;
    for(Node *curr = head; curr!=NULL; curr = curr->next)
    {
        arr.push_back(curr->data);
    }
    for(Node *curr = head; curr!=NULL; curr = curr->next)
    {
        curr->data = arr.back();
        arr.pop_back();
    }

    return head;

}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    head = revList(head);
    printlist(head);
    return 0;

}




//Efficient Solution

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
    Node *curr = head;
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;
    }cout<<endl;
}


Node *reverse(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while(curr!=NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}


int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    printlist(head);
    head = reverse(head);
    printlist(head);
    return 0;
}