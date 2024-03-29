// 2022.12.04
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode* pa = dummy;
        ListNode* pb = dummy;
        while(a--) {
            pa = pa->next;
        }
        while(b-- >= 0) {
            pb = pb->next;
        }
        pb = pb->next;
        pa->next = list2;
        ListNode* p2 = list2;
        while(p2->next) {
            p2 = p2->next;
        }
        p2->next = pb;
        return dummy->next;
    }
};

// 2023.01.30
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = list1;
        ListNode* prea = dummy;
        while(a--) {
            prea = prea->next;
        }
        ListNode* nxtb = dummy->next;
        while(b--) {
            nxtb = nxtb->next;
        }
        nxtb = nxtb->next;
        prea->next = list2;
        ListNode* preb = list2;
        while(preb->next) {
            preb = preb->next;
        }
        preb->next = nxtb;
        return dummy->next;
    }
};