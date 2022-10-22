// 2022.10.22
class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        string st;
        unordered_map<char, bool> ins;
        unordered_map<int, int> last;
        for(int i = 0; i < n; i++) {
            last[s[i]] = i;
        }
        for(int i = 0; i < n; i++) {
            if(ins[s[i]]) {
                continue;
            }
            while(!st.empty() && st.back() > s[i] && last[st.back()] > i) {
                ins[st.back()] = false;
                st.pop_back();
            }
            st += s[i];
            ins[s[i]] = true;
        }
        return st;
    }
};