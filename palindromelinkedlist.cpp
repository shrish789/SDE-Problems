/*

Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?

*/

// FIRST APPROACH: Brute force, offcourse

// SECOND APPROACH: Find length
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head,*prev=NULL;
        int n=0,i=0;
        if(head==NULL || head->next==NULL) return true;
        bool res=true;
        while(temp!=NULL){
            temp=temp->next;
            n++;
        }
        temp=head;
        while(i<n/2){
            prev=temp;
            temp=temp->next;
            i++;
        }
        prev->next=NULL;
        temp=reverseList(temp);
        while(temp!=NULL && head!=NULL){
            if(head->val!=temp->val) res=false;
            head=head->next;
            temp=temp->next;
        }
        return res;
    }
    ListNode* reverseList(ListNode* head){
        ListNode *prev=NULL,*curr=head,*temp;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};


// THIRD APPROACH: Fast-slow pointer and rest approach same as above
