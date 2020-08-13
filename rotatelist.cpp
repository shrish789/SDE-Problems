/*

Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
Example 2:

Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL

*/

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int len=findlen(head);
        k=k%len;
        if(k==0) return head;
        int p=len-k,i=0;
        ListNode *temp=head,*prev=NULL;
        while(i<p){
            i++;
            prev=temp;
            temp=temp->next;
        }
        prev->next=NULL;
        prev=temp;
        while(temp->next!=NULL) temp=temp->next;
        temp->next=head;
        head=prev;
        return head;
    }
    int findlen(ListNode* head){
        int n=0;
        ListNode *temp=head;
        while(temp!=NULL) n++,temp=temp->next;
        return n;
    }
};
