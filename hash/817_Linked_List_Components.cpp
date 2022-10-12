// 2022.10.12
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
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> set;
        int res = 0;
        for(auto& num : nums) {
            set.insert(num);
        }
        while(head != nullptr) {
            if(set.count(head->val)) {
                while(head != nullptr && set.count(head->val)) {
                    head = head->next;
                }
                res++;
            }
            else {
                head = head->next;
            }
        }
        return res;
    }
};