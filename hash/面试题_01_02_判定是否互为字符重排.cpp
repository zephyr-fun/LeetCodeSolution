// 2022.09.27
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        int cnt[26] = {0};
        memset(cnt, 0, sizeof(cnt));
        if(s1.size() != s2.size()) {
            return false;
        }
        for(int i = 0; i < s1.size(); i++) {
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(cnt[i] != 0) {
                return false;
            }
        }
        return true;
    }
};