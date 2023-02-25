// 2023.02.25
class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int cnt[2];
        memset(cnt, 0, sizeof(cnt));
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            if(s1[i] != s2[i]) {
                cnt[s1[i] % 2]++;
            }
        }
        int d = cnt[0] + cnt[1];
        return d % 2 == 1 ? -1 : (cnt[0] % 2 == 0 ? d / 2 : d / 2 + 1);
    }
};