// 2023.09.20
// 首先尝试记录所有的可能的左端点（一定是最快达到最优的，例74（不会出现比2小的还在2前的值）2）
// 然后从后先前遍历枚举可能的右端点，依次匹配左端点，这里用while保证尽可能远地匹配
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        int n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[st.top()]) {
                st.push(i);
            }
        }
        int res = 0;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] >= nums[st.top()]) {
                int cur = st.top();
                st.pop();
                res = max(res, i - cur);
            }
        }
        return res;
    }
};