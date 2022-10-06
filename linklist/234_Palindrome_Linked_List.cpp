// 2022.10.06
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
// forward + recursion(backward)
class Solution {
public:
    ListNode* front;
    bool traversal(ListNode* cur) {
        if(cur == nullptr) {
            return true;
        }
        if(!traversal(cur->next)) {
            return false;
        }
        if(front->val != cur->val) {
            return false;
        }
        front = front->next;
        return true;
    }
    bool isPalindrome(ListNode* head) {
        front = head;
        return traversal(head);
    }
};