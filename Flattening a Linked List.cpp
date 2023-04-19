/*

https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Problem Statement: Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:

(i) a next pointer to the next node,

(ii) a bottom pointer to a linked list where this node is head.

Each of the sub-linked-list is in sorted order.

Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 

Note: The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Example 1:
Input:
Number of head nodes = 4
Array holding length of each list with head and bottom = [4,2,3,4]
Elements of entire linked list = [5,7,8,30,10,20,19,22,50,28,35,40,45]


Output:
 Flattened list = [5,7,8,10,19,20,22,28,30,35,40,45,50]
Explanation:
 Flattened list is the linked list consisting entire elements of the given list in sorted order
 
 */

// APPROACH: Start merging two linked lists from last and voila

Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->bottom = a; 
            temp = temp->bottom; 
            a = a->bottom; 
        }
        else {
            temp->bottom = b;
            temp = temp->bottom; 
            b = b->bottom; 
        }
    }
    
    if(a) temp->bottom = a; 
    else temp->bottom = b; 
    
    return res -> bottom; 
    
}
Node *flatten(Node *root)
{
   
        if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        root->next = flatten(root->next); 
  
        // now merge 
        root = mergeTwoLists(root, root->next); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}


// My solution using Loops
Node *flatten(Node *root)
{
   // Your code here
   Node *curr = root, *temp;
   while (curr) {
       if (curr -> bottom && curr -> next) {
           if (curr -> bottom -> data <= curr -> next -> data) {
               temp = curr -> next;
               curr -> next = curr -> bottom;
               curr -> bottom = NULL;
               curr -> next -> next = temp;
           } else {
               // Rocket science
               Node * temp1 = curr -> next, *temp2 = NULL;
               while (temp1 && temp1 -> data < curr -> bottom -> data) {
                   temp2 = temp1;
                   temp1 = temp1 -> next;
               }
               temp2 -> next = curr -> bottom;
               curr -> bottom -> next = temp1;
               curr -> bottom = NULL;
           }
       } else if (curr -> bottom && !curr -> next) {
           curr -> next = curr -> bottom;
           curr -> bottom = NULL;
       }
       curr = curr -> next;
   }
   curr = root;
   while (curr) {
       curr -> bottom = curr -> next;
       curr -> next = NULL;
       curr = curr -> bottom;
   }
   return root;
}

