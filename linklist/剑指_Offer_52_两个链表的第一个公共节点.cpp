// 2022.08.02
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n = 0;
        int m = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr) {
            n++;
            curA = curA->next;
        }
        while(curB != nullptr) {
            m++;
            curB = curB->next;
        }
        if(n < m) {
            return getIntersectionNode(headB, headA);
        }
        int temp = n - m;
        curA = headA;
        curB = headB;
        while(temp) {
            curA = curA->next;
            temp--;
        }
        while(curA != nullptr) {
            if(curA == curB) {
                 return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};

// stackn and set also work

// 2022.08.19
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        int len2 = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while(curA != nullptr) {
            len1++;
            curA = curA->next;
        }
        while(curB != nullptr) {
            len2++;
            curB = curB->next;
        }
        if(len2 > len1) {
            return getIntersectionNode(headB, headA);
        }
        int diff = len1 - len2;
        curA = headA;
        curB = headB;
        while(diff) {
            curA = curA->next;
            diff--;
        }
        while(curA != nullptr && curB != nullptr) {
            if(curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return nullptr;
    }
};