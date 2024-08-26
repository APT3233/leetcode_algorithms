/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* swapPairs(struct ListNode* head) {
    if(head == NULL)    return NULL;
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* current = dummy;

    while(current->next != NULL && current->next->next != NULL){
        struct ListNode* first = current->next;
        struct ListNode* second = current->next->next;

        first->next = second->next;
        current->next = second;
        second->next = first;

        current = current->next->next;
    }
    
    return dummy->next;

}