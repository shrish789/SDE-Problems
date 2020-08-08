/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp,*temp1,*temp2;
        temp=l1;
        temp1=l1,temp2=l2;
        int sum=0,carry=0;
        while(1){
            sum=temp1->val+temp2->val+carry;
            carry=sum/10;
            sum=sum%10;
            temp1->val=sum;
            temp2->val=sum;
            if(temp1->next==NULL || temp2->next==NULL) break;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        if(temp1->next!=NULL){
            temp1=temp1->next;
            while(1){
                sum=temp1->val+carry;
                carry=sum/10;
                sum=sum%10;
                temp1->val=sum;
                if(temp1->next==NULL) break;
                temp1=temp1->next;
            }
            temp=l1;
        }
        if(temp2->next!=NULL){
            temp2=temp2->next;
            while(1){
                sum=temp2->val+carry;
                carry=sum/10;
                sum=sum%10;
                temp2->val=sum;
                if(temp2->next==NULL) break;
                temp2=temp2->next;
            }
            temp=l2;
        }
        if(carry!=0){
            ListNode *ptr = new ListNode(carry);
            if(temp==l1) temp1->next=ptr;
            else temp2->next=ptr;
        }
        return temp;
    }
};
