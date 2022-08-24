// 2022.08.24
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
    ListNode* rotateRight(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while(cur != nullptr) {
            n++;
            cur = cur->next;
        }
        if(n == 0) {
            return head;
        }
        k = k % n;
        if(k == 0) {
            return head;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(k--) {
            fast = fast->next;
        }
        fast = fast->next;
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* res = slow->next;
        slow->next = nullptr;
        ListNode* temp = res;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = head;
        return res;
    }
};