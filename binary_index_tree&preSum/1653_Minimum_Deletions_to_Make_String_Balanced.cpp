// 2023.03.06
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        if(n == 1) {
            return 0;
        }
        int cnt[n + 1];
        memset(cnt, 0, sizeof(cnt));
        for(int i = 0; i < n; i++) {
            cnt[i + 1] = cnt[i] + (s[i] == 'a' ? 1 : 0);
        }
        int res = 0x3f3f3f3f;
        for(int i = 0; i <= n; i++) {
            res = min(res, i - cnt[i] + cnt[n] - cnt[i]);
        }
        return res;
    }
};