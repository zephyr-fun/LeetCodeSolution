// 2022.10.09
// https://leetcode.cn/circle/discuss/YNdXJT/
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> rightMin(n + 1);
        rightMin[n] = 'z' + 1;
        for(int i = n - 1; i >= 0; i--) {
            rightMin[i] = min(rightMin[i + 1], s[i]);
        }
        stack<int> st;
        string res = "";
        for(int i = 0; i < n; i++) {
            st.push(s[i]);
            while(!st.empty() && st.top() <= rightMin[i + 1]) {
                res += st.top();
                st.pop();
            }
        }
        return res;
    }
};