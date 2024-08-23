/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* newNode(int value){
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
 }
bool hasCycle(struct ListNode *head) {
    struct ListNode *first = head;
    struct ListNode *second = head;

    while(first != NULL && first->next != NULL){
        first = first->next->next;
        second = second->next; 
    
        if(first == second){
            return true;
        }
    }
    return false;
}