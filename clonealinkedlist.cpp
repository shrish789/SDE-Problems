/*

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.
 

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]


Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]


Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]


Example 4:
Input: head = []
Output: []
Explanation: Given linked list is empty (null pointer), so return null.
 

Constraints:

-10000 <= Node.val <= 10000
Node.random is null or pointing to a node in the linked list.
Number of Nodes will not exceed 1000.

*/

// Hashing Approach

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *newHead = new Node(head->val);
        unordered_map<Node*,Node*> mymap;
        Node *temp = head,*temp1=newHead;
        mymap[head] = newHead;
        temp=head->next;
        while(temp!=NULL){
            Node *newNode = new Node(temp->val);
            mymap[temp] = newNode;
            temp1->next = newNode;
            temp=temp->next;
            temp1=temp1->next;
        }
        temp1->next = NULL;
        temp1 = newHead;
        temp = head;
        while(temp != NULL){
            temp1->random = mymap[temp->random];
            temp = temp->next;
            temp1 = temp1->next;
        }
        return newHead;
    }
};


// Approach without hashing O(1) space

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return NULL;
        Node *curr = head, *temp;
        while(temp){
            temp = curr->next;
            Node *newNode = new Node(curr->val);
            curr->next = newNode;
            newNode->next = temp;
            curr = temp;
        }
        curr=head;
        while(curr){
            if(curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        curr = head;
        Node *newHead = curr->next;
        temp = newHead;
        while(curr){
            curr->next = curr->next->next;
            if(temp->next) temp->next = temp->next->next;
            curr = curr->next;
            temp = temp->next;
        }
        return newHead;
    }
};
