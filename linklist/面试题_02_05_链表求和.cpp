// 2022.07.02
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        dummy->next = l1;
        while(l1 != nullptr && l2 != nullptr) {
            int temp = l1->val;
            l1->val = (temp + l2->val + carry) % 10;
            carry = (temp + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
            head = head->next;
        }
        if(l1 != nullptr) {
            while(carry != 0 && l1 != nullptr) {
                int temp = l1->val;
                l1->val = (temp + carry) % 10;
                carry = (temp + carry) / 10;
                l1 = l1->next;
                head = head->next;
            }
        }
        if(l2 != nullptr) {
            head->next = l2;
            while(carry != 0 && l2 != nullptr) {
                int temp = l2->val;
                l2->val = (temp + carry) % 10;
                carry = (temp + carry) / 10;
                l2 = l2->next;
                head = head->next;
            }
        }
        if(carry != 0) {
            head->next = new ListNode(carry);
        }
        return dummy->next;
    }
};

// optim, elegant
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        int temp = 0;
        while(l1 != nullptr || l2 != nullptr || temp != 0) {
            if(l1 != nullptr) {
                temp += l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr) {
                temp += l2->val;
                l2 = l2->next;
            }
            head->next = new ListNode(temp % 10);
            head = head->next;
            temp /= 10;
        }
        return dummy->next;
    }
};