class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr) {
            ListNode* nextNode = curr->next; // save next
            curr->next = prev;               // reverse pointer
            prev = curr;                     // move prev forward
            curr = nextNode;                 // move curr forward
        }

        return prev;
    }
};
