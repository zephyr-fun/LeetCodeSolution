/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 2022.03.31
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr){
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr){
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenA < lenB){
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;
        while(gap--){
            curA = curA->next;
        }
        while(curA != nullptr){
            if(curA == curB){
                return curA;
            }
            else{
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};

// 2022.04.19
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr) {
            lenA++;
            curA = curA->next;
        }
        while(curB != nullptr) {
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if(lenA < lenB) {
            swap(curA, curB);
            swap(lenA, lenB);
        }
        int gap = lenA - lenB;
        while(gap--) {
            curA = curA->next;
        }
        while(curA != nullptr) {
            if(curA == curB) {
                return curA;
            }
            else {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};