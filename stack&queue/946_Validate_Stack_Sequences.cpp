// 2022.08.31
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        for(int i = 0, j = 0; i < n; i++) {
            st.push(pushed[i]);
            while(!st.empty() && st.top() == popped[j] && j < n) {
                j++;
                st.pop();
            }
        }
        return st.empty();
    }
};