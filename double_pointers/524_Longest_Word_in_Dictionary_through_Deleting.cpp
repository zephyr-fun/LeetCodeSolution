// 2023.02.28
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n = s.size();
        int m;
        sort(dictionary.begin(), dictionary.end(), [] (string& a, string& b) {
            if(a.size() == b.size()) {
                return a < b;
            }
            return a.size() > b.size();
        });
        for(auto& dic : dictionary) {
            m = dic.size();
            int ptr1 = 0;
            int ptr2 = 0;
            while(ptr1 < n && ptr2 < m) {
                if(s[ptr1] == dic[ptr2]) {
                    ptr2++;
                }
                ptr1++;
            }
            if(ptr2 == m) {
                return dic;
            }
        }
        return "";
    }
};