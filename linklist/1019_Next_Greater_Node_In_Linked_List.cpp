// 2023.04.10
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
    vector<int> nextLargerNodes(ListNode* head) {
        int n = 0;
        ListNode* cur = head;
        while(cur) {
            n++;
            cur = cur->next;
        }
        vector<int> res(n, 0);
        stack<pair<ListNode*, int>> st;
        int idx = 0;
        cur = head;
        while(cur) {
            while(!st.empty() && cur->val > st.top().first->val) {
                res[st.top().second] = cur->val;
                st.pop();
            }
            st.push({cur, idx});
            idx++;
            cur = cur->next;
        }
        return res;
    }
};