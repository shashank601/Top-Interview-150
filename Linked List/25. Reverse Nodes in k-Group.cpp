
class Solution {
public:
    pair<ListNode*,ListNode*> reverse(ListNode* start, ListNode* end) {
        ListNode* mark = end->next; // it get modified (end node start pointing prev node)
        ListNode* curr = start;
        ListNode* prev = nullptr;
        while (curr && curr != mark) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return {end, start};
    }


    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* old_grp_tail = nullptr;
        
        while (temp) {

            // --------------------
            ListNode*  grp_start = temp;

            int cnt = 0;
            while (temp && cnt < k - 1) {
                temp = temp->next;
                cnt += 1;
            }
            // if dont have k nodes return
            if (!temp) return head;
            
            ListNode* grp_tail = temp;


            // --------------------


            // --------------------
            ListNode* next_grp_head = grp_tail->next;
            
            
            temp = next_grp_head;


            auto p = reverse(grp_start, grp_tail);
            grp_start = p.first;
            grp_tail = p.second;

            grp_tail->next = next_grp_head;

            if (old_grp_tail)
                old_grp_tail->next =  grp_start;
            else
                head = grp_start;

            
            
            old_grp_tail = grp_tail;


            // --------------------

        }

        return head;

    }
};
