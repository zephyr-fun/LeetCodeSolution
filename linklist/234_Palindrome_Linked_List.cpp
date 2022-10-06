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

// half way reverse
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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow->next == nullptr) {
            return true;
        }
        slow->next = reverseList(slow->next);
        ListNode* temp = slow->next;
        fast = head;
        while(temp) {
            if(fast->val != temp->val) {
                return false;
            }
            fast = fast->next;
            temp = temp->next;
        }
        return true;
    }
};