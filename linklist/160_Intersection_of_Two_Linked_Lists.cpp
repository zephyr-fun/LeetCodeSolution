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

// 2022.10.02
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
        ListNode* a = headA;
        ListNode* b = headB;
        int cnta = 0;
        int cntb = 0;
        while(a) {
            cnta++;
            a = a->next;
        }
        while(b) {
            cntb++;
            b = b->next;
        }
        if(cnta > cntb) {
            return getIntersectionNode(headB, headA);
        }
        int diff = cntb - cnta;
        a = headA;
        b = headB;
        while(diff) {
            b = b->next;
            diff--;
        }
        while(a && b) {
            if(a == b) {
                return a;
            }
            a = a->next;
            b = b->next;
        }
        return nullptr;
    }
};

// 2022.10.22
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
        if(m > n) {
            return getIntersectionNode(headB, headA);
        }
        int len = n - m;
        curA = headA;
        curB = headB;
        while(len--) {
            curA = curA->next;
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