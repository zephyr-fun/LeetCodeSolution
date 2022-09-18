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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){ // cause fast goes two steps one time step, you have to make sure fast and fast->next != nullptr, so that fast->next->next won't raise error
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* index1 = slow;
                ListNode* index2 = head;
                while(index1 != index2){
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index2;
            }
        }
        return nullptr;
    }
};

// 2022.04.17
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode* node1 = slow;
                ListNode* node2 = head;
                while(node1 != node2) {
                    node1 = node1->next;
                    node2 = node2->next;
                }
                return node1;
            }
        }
        return nullptr;
    }
};

// 2022.09.18
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         while(fast != nullptr && fast->next != nullptr) {
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow == fast) {
//                 ListNode* node1 = slow;
//                 ListNode* node2 = head;
//                 while(node1 != node2) {
//                     node1 = node1->next;
//                     node2 = node2->next;
//                 }
//                 return node1;
//             }
//         }
//         return nullptr;
//     }
// };
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {
                ListNode* node1 = head;
                ListNode* node2 = slow;
                while(node1 != node2) {
                    node1 = node1->next;
                    node2 = node2->next;
                }
                return node1;
            }
        }
        return nullptr;
    }
};