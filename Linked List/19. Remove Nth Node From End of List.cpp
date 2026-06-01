class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dmy = new ListNode(-1, head);
        ListNode* temp = head;

        ListNode* slow = dmy;
        ListNode* fast = head;

        while (n--) {
            fast = fast->next;
        }

        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* target = slow->next;
        if (!target) return head;

        slow->next = target->next;
        delete target;


        return dmy->next;
    }
};
