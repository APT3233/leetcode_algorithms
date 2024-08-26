/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = head;
    struct ListNode* res = dummy;

    for (int i = 0; i < n; i++)
        head = head->next;
    
    while (head != NULL)
    {
        head = head->next;
        res = res->next;
    }

    res->next = res->next->next;

    return dummy->next;

}