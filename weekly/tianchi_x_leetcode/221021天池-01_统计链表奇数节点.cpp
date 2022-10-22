// 2022.10.22
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
    int numberEvenListNode(ListNode* head) {
        int res = 0;
        while(head != nullptr) {
            if(head->val % 2) {
                res++;
            }
            head = head->next;
        }
        return res;
    }
};