// 2022.11.11
class Solution {
public:
    bool halvesAreAlike(string s) {
        int a = 0;
        int cur = 0;
        string hash = "aeiouAEIOU";
        for(int i = 0; i < s.size(); i++) {
            if(hash.find(s[i]) != std::string::npos) {
                cur++;
            }
            if(i == s.size() / 2 - 1) {
                a = cur;
            }
        }
        return a == cur - a;
    }
};