// 2022.06.30
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while(list1 && list2) {
            if(list1->val > list2->val) {
                dummy->next = list2;
                list2 = list2->next;
            }
            else {
                dummy->next = list1;
                list1 = list1->next;
            }
            dummy = dummy->next;
        }
        if(list1 != nullptr) {
            dummy->next = list1;
        }
        else if(list2 != nullptr){
            dummy->next = list2;
        }
        return head->next;
    }
};

// recursion
// intresting version
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr) {
            return list2;
        }
        if(list2 == nullptr) {
            return list1;
        }
        if(list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
};