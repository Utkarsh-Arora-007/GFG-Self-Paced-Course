//Naive Solution : Swapping Data
// Time Complexity : Theta(n) and Aux Space : O(1)

Node *pairWiseSwap(Node *head)
{
    Node *curr = head;
    while(curr != NULL && curr->next!=NULL)
    {
        swap(curr->data , curr->next->data);

        curr = curr->next->next;
    }
    return head;
}


//Efficient Solution : Handle 2 Nodes Explicitly

Node *pairWiseSwap(Node *head)
{
    if(head == NULL and head->next == NULL)
         return head;

    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;
    while(curr!=NULL && curr->next!=NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }     

    prev->next = curr;
    return head;
}