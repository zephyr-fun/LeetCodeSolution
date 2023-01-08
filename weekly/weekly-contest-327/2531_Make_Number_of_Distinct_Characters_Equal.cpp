// 2023.01.08
class Solution {
public:
    bool isItPossible(string word1, string word2) {
        int map1[26];
        int map2[26];
        memset(map1, 0, sizeof(map1));
        memset(map2, 0, sizeof(map2));
        for(auto& s : word1) {
            map1[s - 'a']++;
        }
        for(auto& s : word2) {
            map2[s - 'a']++;
        }
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++) {
                if(map1[j] == 0 || map2[i] == 0) {
                    continue;
                }
                map1[i]++;
                map2[i]--;
                map1[j]--;
                map2[j]++;
                int cnt1 = 0;
                int cnt2 = 0;
                for(int k = 0; k < 26; k++) {
                    if(map1[k] > 0) {
                        cnt1++;
                    }
                    if(map2[k] > 0) {
                        cnt2++;
                    }
                }
                if(cnt1 == cnt2) {
                    return true;
                }
                map1[i]--;
                map2[i]++;
                map1[j]++;
                map2[j]--;
            }
        }
        return false;
    }
};