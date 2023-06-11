// 2023.06.11
// hash + presum
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        unordered_map<int, ListNode*> map;
        ListNode* cur = dummy;
        int s = 0;
        while(cur != nullptr) {
            s += cur->val;
            map[s] = cur;
            cur = cur->next;
        }
        s = 0;
        cur = dummy;
        while(cur != nullptr) {
            s += cur->val;
            cur->next = map[s]->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};