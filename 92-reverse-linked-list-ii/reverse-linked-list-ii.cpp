class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right)
            return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        ListNode* prevSub = nullptr;

        for (int i = 0; i <= right - left; i++) {
            next = curr->next;
            curr->next = prevSub;
            prevSub = curr;
            curr = next;
        }

        prev->next->next = curr;
        prev->next = prevSub;

        return dummy.next;
    }
};
