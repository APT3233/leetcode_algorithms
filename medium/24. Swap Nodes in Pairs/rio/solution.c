/**
 * Definition for singly-linked list.
 **/
struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *swapPairs(struct ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    struct ListNode *dummyNode = head->next;
    struct ListNode *firstNode = head;
    struct ListNode *secondNode = head->next;
    struct ListNode *prev = NULL;

    while (firstNode != NULL && secondNode != NULL)
    {
        firstNode->next = secondNode->next;
        secondNode->next = firstNode;

        if (prev != NULL)
        {
            prev->next = secondNode;
        }

        prev = firstNode;
        firstNode = firstNode->next;

        if (firstNode != NULL)
        {
            secondNode = firstNode->next;
        }
    }
    return dummyNode;
}