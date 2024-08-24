/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int cmp(const void* a, const void* b){
    struct ListNode** nodeA = (struct ListNode**)a;
    struct ListNode** nodeB = (struct ListNode**)b;
    return (nodeA*)->val - (nodeB*)->val;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 0)  return NULL; 
    struct ListNode** minHeap = (struct ListNode**)malloc(listsSize * sizeof(struct ListNode*))

    int heapSize = 0;
    for (int i = 0; i < listsSize; i++)
        if(lists[i] != NULL)
            minHeap[heapSize++] = lists[i];

    qsort(minHeap, heapSize, sizeof(struct ListNode*), cmp);

    struct ListNode dummy;
    struct ListNode* tail = dummy;

    while(heapSize > 0){
        struct ListNode* node = minHeap[0];
        minHeap[0] = minHeap[--heapSize];

        qsort(minHeap, heapSize, sizeof(struct ListNode*), cmp);

        tail->next = node;
        tail = tail->next;

        if(node->next != NULL){
            minHeap[heapSize++] = node->next;
            qsort(minHeap, heapSize, sizeof(struct ListNode*), cmp);
        }   
    }
    free(minHeap); 
    return dummy.next;
}