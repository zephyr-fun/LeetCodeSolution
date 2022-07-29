// 2022.07.29
// yxc version
// start means delimiter
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int res = 0;
        int n = s.size();
        for(int i = 0, start = -1; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(!st.empty()) {
                    st.pop();
                    if(!st.empty()) {
                        res = max(res, i - st.top());
                    }
                    else {
                        res = max(res, i - start);
                    }
                }
                else {
                    start = i; // move to next paragraph
                }
            }
        }
        return res;
    }
};

// with the last unmatched ')'
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> st;
        int n = s.size();
        st.push(-1);
        for(int i = 0; i < n; i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if(!st.empty()) {
                    res = max(res, i - st.top());
                }
                else {
                    st.push(i);
                }
            }
        }
        return res;
    }
};

// dp
class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for(int i = 1; i < n; i++) {
            if(s[i] == ')') {
                if(s[i - 1] == '(') {
                    dp[i] = (i - 2 >= 0 ? dp[i - 2] : 0) + 2; // note ()
                }
                else if(i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] - 2 >= 0 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};