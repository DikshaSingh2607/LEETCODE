
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

        // Min heap
        priority_queue<ListNode*, vector<ListNode*>,
        decltype([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        })> pq;

        // Insert first node of every list
        for (auto list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Get smallest node
            ListNode* smallest = pq.top();
            pq.pop();

            // Attach to result
            tail->next = smallest;
            tail = tail->next;

            // Insert next node
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};
