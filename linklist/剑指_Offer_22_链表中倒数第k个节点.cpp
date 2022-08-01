// 2022.08.01
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        while(k) {
            fast = fast->next;
            k--;
        }
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};