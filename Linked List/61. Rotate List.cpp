
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!k || !head) return head;
        
        int cnt = 0;

        ListNode* node = head;
        while (node) {
            node = node->next;
            cnt++;
        }


        k = k % cnt;
        if (!k) return head;


        node = head;

        int jmp = cnt - k - 1;
        while (node && jmp >= 1) {
            node = node->next;
            jmp--;
        }

        ListNode* original_head = head;

        head = node->next;

        node->next = nullptr;

        ListNode* old_head = head;
        while (old_head->next) {
            old_head = old_head->next;
        }

        old_head->next = original_head;

        return head;
    }
};

======

optimization:

at intial traversal make nodes circular this will avoid last loop to attach tail to head


=====

issues encountered 

no null check and div by 0  (% cnt)
