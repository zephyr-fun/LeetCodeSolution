// 2023.05.16
class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        int res = 0;
        int n = input.size();
        for(int i = 0, sum = 0; i < n; i++) {
            int depth = 0;
            while(i < n && input[i] == '\t') {
                i++;
                depth++;
            }
            while(st.size() > depth) {
                sum -= st.top();
                st.pop();
            }
            int j = i;
            while(j < n && input[j] != '\n') {
                j++;
            }
            int len = j - i;
            st.push(len);
            sum += len;
            if(input.substr(i, len).find('.') != -1) {
                res = max(res, sum + (int)st.size() - 1);
            }
            i = j;
        }
        return res;
    }
};