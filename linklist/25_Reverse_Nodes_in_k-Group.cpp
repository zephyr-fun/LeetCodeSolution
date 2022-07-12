// 2022.07.12
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
// draw a picture
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) {
            return head;
        }
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur != nullptr) {
            auto prob = cur;
            for(int i = 0; i < k && prob != nullptr; i++) {
                prob = prob->next;
            }
            if(prob == nullptr) {
                break;
            }
            auto a = cur->next;
            auto b = a->next;
            for(int i = 0; i < k - 1; i++) {
                auto c = b->next;
                b->next = a;
                a = b;
                b = c;
            }
            auto c = cur->next;
            cur->next = a;
            c->next = b;
            cur = c;
        }
            
        return dummy->next;
    }
};