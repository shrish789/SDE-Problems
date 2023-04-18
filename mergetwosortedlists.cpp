/*

Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

//Recursive Solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;

        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};

//Iterative Solution

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head,*temp1,*temp2,*prev,*tempo;
        if(l2==NULL) return l1;
        else if(l1==NULL) return l2;
        if(l1->val > l2->val)
        {
            cout<<"HI";
            return mergeTwoLists(l2, l1);
        }
        head = l1;
        temp1=head->next;
        temp2=l2;
        prev=head;
        while(temp1!=NULL && temp2!=NULL)
        {
            cout<<prev->val<<" "<<temp1->val<<" "<<temp2->val<<"\n";
            if(temp1->val<temp2->val)
            {
                prev->next = temp1;
                tempo = temp1->next;
                temp1->next = temp2;
                temp1 = tempo;
                prev = prev->next;
            }
            else
            {
                prev->next = temp2;
                tempo = temp2->next;
                temp2->next = temp1;
                temp2 = tempo;
                prev = prev->next;
            }
        }
        if(temp1!=NULL)
        {
            prev->next = temp1;
        }
        if(temp2!=NULL)
            prev->next = temp2;
        return head;
    }
};

// Iterative but better
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;
        ListNode *head = list1, *temp;
        if (list1 -> val < list2 -> val) {
            list1 = list1 -> next;
        } else {
            head = list2;
            list2 = list2 -> next;
        }
        temp = head;
        while (list1 && list2) {
            if (list1 -> val < list2 -> val) {
                temp -> next = list1;
                list1 = list1 -> next;
            } else {
                temp -> next = list2;
                list2 = list2 -> next;
            }
            temp = temp -> next;
        }

        if (!list1) {
            temp -> next = list2;
        } else {
            temp -> next = list1;
        }
        return head;
    }
};
