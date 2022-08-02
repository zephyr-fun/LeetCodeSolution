// 2022.08.02
// non recrrsion
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        while(head != nullptr) {
            res.emplace_back(head->val);
            head = head->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

// recursion
class Solution {
public:
    vector<int> res;
    void dfs(ListNode* cur) {
        if(cur == nullptr) {
            return ;
        }
        dfs(cur->next);
        res.emplace_back(cur->val);
    }
    vector<int> reversePrint(ListNode* head) {
        dfs(head);
        return res;
    }
};