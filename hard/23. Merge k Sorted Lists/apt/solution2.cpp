/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Nút giả để tạo điểm bắt đầu cho danh sách kết quả
        ListNode dummy(0);
        ListNode* current = &dummy;

        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            current->next = node;
            current = current->next;
            
            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
    struct Compare {
        bool operator()(ListNode* l1, ListNode* l2) {
            return l1->val > l2->val;
        }
    };
};