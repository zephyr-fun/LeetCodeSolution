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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val >= l2->val) {
                dummy->next = l2;
                dummy = dummy->next;
                l2 = l2->next;
            }
            else {
                dummy->next = l1;
                dummy = dummy->next;
                l1 = l1->next;
            }
        }
        dummy->next = l1 == nullptr ? l2 : l1;
        return head->next;
    }
};

// recursion
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) {
            return l2;
        }
        if(l2 == nullptr) {
            return l1;
        }
        if(l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
};