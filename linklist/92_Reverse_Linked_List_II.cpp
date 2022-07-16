// 2022.07.16
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
    pair<ListNode*, ListNode*> reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(head != nullptr) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return {prev, cur};
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* leftNode = dummy;
        left--;
        while(left > 0) {
            leftNode = leftNode->next;
            left--;
        }
        ListNode* rightNode = dummy;
        while(right > 0) {
            rightNode = rightNode->next;
            right--;
        }
        ListNode* leftTemp = leftNode->next;
        leftNode->next = nullptr;
        ListNode* rightTemp = rightNode->next;
        rightNode->next = nullptr;
        auto [newLeft, newRight] = reverseList(leftTemp);
        leftNode->next = newLeft;
        newRight->next = rightTemp;
        return dummy->next;
    }
};