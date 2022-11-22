// 2022.11.22
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* last = head;
        ListNode* cur = head->next;
        while(cur != nullptr) {
            if(cur->val >= last->val) {
                last = last->next;
            }
            else {
                ListNode* prev = dummy;
                while(prev->next->val <= cur->val) {
                    prev = prev->next;
                }
                last->next = cur->next;
                cur->next = prev->next;
                prev->next = cur;
            }
            cur = last->next;
        }
        return dummy->next;
    }
};