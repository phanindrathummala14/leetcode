class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Min-heap based on node value
        priority_queue<ListNode*, vector<ListNode*>, 
            function<bool(ListNode*, ListNode*)>> pq(
            [](ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        );

        // Push initial nodes
        for (auto list : lists) {
            if (list) pq.push(list);
        }

        ListNode dummy;
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node;
            tail = tail->next;

            if (node->next) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
