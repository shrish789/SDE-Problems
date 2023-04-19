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
private:
    int listLength(ListNode *head) {
        ListNode *temp = head;
        int len = 0;
        while (temp) {
            len++;
            temp = temp -> next;
        }
        return len;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int n = listLength(head);
        k = k % n;
        if (!k) return head;
        int k1 = n - k, i = 1;
        ListNode *curr = head, *prev = NULL;
        ListNode *newHead = head;
        while(curr -> next) {
            if (i == k1)
                prev = curr;
            curr = curr -> next;
            i++;
        }
        newHead = prev -> next;
        prev -> next = NULL;
        curr -> next = head;
        return newHead;
    }
};
