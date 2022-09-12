// 2022.09.12
class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string cur = "";
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                st.push(cur);
                cur = "";
            }
            else if(s[i] == ')') {
                string temp = st.top();
                st.pop();
                // in case the test sample is not valid
                // if(!st.empty()) {
                //     temp = st.top();
                //     st.pop();
                // }
                reverse(cur.begin(), cur.end());
                cur = temp + cur;
            }
            else {
                cur += s[i];
            }
        }
        return cur;
    }
};