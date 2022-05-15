// 2022.05.15
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        stack<string> st;
        for(int i = words.size() - 1; i > 0; i--) {
            string cur = words[i];
            string prev = words[i - 1];
            sort(cur.begin(), cur.end());
            sort(prev.begin(), prev.end());
            if(cur == prev) {
                continue;
            }
            else {
                st.push(words[i]);
            }
        }
        res.push_back(words[0]);
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }
        return res;
    }
};