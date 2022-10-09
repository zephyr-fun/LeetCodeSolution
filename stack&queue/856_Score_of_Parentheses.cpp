// 2022.10.09
class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        for(auto c : s) {
            if(c == '(') {
                st.push(0);
            }
            else {
                int cur = st.top();
                st.pop();
                int next = st.top() + max(cur * 2, 1);
                st.pop();
                st.push(next);
            }
        }
        return st.top();
    }
};