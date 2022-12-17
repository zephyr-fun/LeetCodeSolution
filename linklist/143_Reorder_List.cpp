// 2022.12.17
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
    // find middle node
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // reverse
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur) {
            ListNode* nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

public:
    void reorderList(ListNode *head) {
        ListNode* mid = middleNode(head);
        ListNode* head2 = reverseList(mid);
        while(head2->next) {
            ListNode* nxt = head->next;
            ListNode* nxt2 = head2->next;
            head->next = head2;
            head2->next = nxt;
            head = nxt;
            head2 = nxt2;
        }
    }
};