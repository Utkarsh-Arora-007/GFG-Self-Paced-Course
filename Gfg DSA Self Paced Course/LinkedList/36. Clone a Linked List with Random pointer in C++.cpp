//Method 1: Hashing
// 1. Create an unordered_map
// 2. Do Following for every node
//    curr in the given __builtin_va_list
  
//    m[curr] = new Node(curr->data)


// 3. Traverse the given list again and do following for every node curr

//    m[arr]->next = m[curr->next];
//    m[curr]->random = m[curr->random]


// 4. return m[h1] 


//Time Complexity : Theta (n) and Aux Space :Theta(n)

Node *clone(Node *h1)
{
    unordered_map<Node* , Node*> m;
    for(Node *curr = h1; curr!=NULL; curr = curr->next)
          m[curr] = new Node(curr->data);


    for(Node *curr = h1; curr!=NULL; curr = curr->next)
    {
        m[curr].next = m[curr->next];
        m[curr].random = m[curr->random];
    }      

    return m[h1];
    
}


//Method 2: Efficient Solution

// 1. Create Clone Nodes and Insert in the given list at alternate positions.

// 2. Connect the clone nodes. 

// 3. Seperate the original and Clone Nodes.


Node *clone(Node *h1)
{

    //STEP 1: Insert Clone Nodes Alternatively
    Node *curr = h1;
    while(curr!=NULL)
    {
        Node *next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }



    //STEP 2: Connect Clone Nodes with Random

    for(Node *curr = h1; curr!= NULL; curr = curr->next->next)
    {
        curr->next->random = (curr->random == NULL) ? NULL : curr->random->next;
    }



    //STEP 3: Seperate Original and Clone Nodes

    Node *h2 = h1->next;
    Node *clone = h2;

    for(Node *curr = h2; curr!=NULL ; curr = curr->next)
    {
        curr->next = curr->next->next;
        clone->next = clone->next ? clone->next->next: NULL;
        clone = clone->next;
    }


 return h2;

}
