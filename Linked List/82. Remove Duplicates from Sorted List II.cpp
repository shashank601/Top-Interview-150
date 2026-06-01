
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dmy = new ListNode(-1, head);
        ListNode* temp = dmy->next;
        ListNode* prev = dmy;

        while (temp) {
            // identify
            ListNode* grp_start = temp;
            ListNode* grp_end = temp;

            while (temp && temp->next && temp->next->val == temp->val) {
                temp = temp->next;
                grp_end = temp;
            }


            // remove
            if (grp_end != grp_start) {
                ListNode* new_start = grp_end->next;

                while (new_start != grp_start) {
                    ListNode* nxt = grp_start->next;
                    delete grp_start;
                    
                    grp_start = nxt;
                }
                temp = new_start;
                prev->next = new_start;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }

        return dmy->next;
    }
};
