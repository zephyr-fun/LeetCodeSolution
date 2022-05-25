class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        int p[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int mod = 1e9 + 7;
        vector<int> cnt(35, 0);
        for(int i = 0; i < nums.size(); i++) {
            cnt[nums[i]]++;
        }
        int n = nums.size();
        int mask = 1 << 10;
        vector<long> dp(mask, 0);
        dp[0] = 1;
        for(int i = 2; i <= 30; i++) {
            if(cnt[i] == 0) {
                continue;
            }
            int cur = 0;
            int x = i;
            bool ok = true;
            for(int j = 0; j < 10; j++) {
                int t = p[j];
                int c = 0;
                while(x % t == 0) {
                    cur |= (1 << j);
                    x /= t;
                    c++;
                }
                if(c > 1) {
                    ok = false;
                    break;
                }
            }
            if(!ok) {
                continue;
            }
            for(int prev = mask - 1; prev >= 0; prev--) {
                if((prev & cur) != 0) {
                    continue;
                }
                dp[prev | cur] = (dp[prev | cur] + dp[prev] * cnt[i]) % mod;
            }
        }
        long res = 0;
        for(int i = 1; i < mask; i++) {
            res = (res + dp[i]) % mod;
        }
        for(int i = 0; i < cnt[1]; i++) {
            res = (res * 2) % mod;
        }
        return int(res);
    }
};