/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
   struct ListNode* head = malloc(sizeof(struct ListNode));
                    head->val = 0;
                    head->next =NULL;



   struct ListNode* l3 = head;
   int carry = 0;
   while(l1 != NULL || l2 != NULL){
    int i = (l1 != NULL) ? l1->val : 0;
    int j = (l2 != NULL) ? l2->val : 0;


    int k = i + j + carry;

    carry = k / 10;
    int last_digit = k % 10;

    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = last_digit;
    newNode->next = NULL;


    l3->next = newNode;

    if(l1 != NULL) l1 = l1->next;
    if(l2 != NULL) l2 = l2->next;

    l3 = l3->next;
   }

   if(carry > 0){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = carry;
    newNode->next = NULL;

    l3->next = newNode;
   }
   return head->next;

}