// 2022.11.18
class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long res = 0, mod = 1e9 + 7;
        long long x = nums[0], y = 2;
        for(int j = 1; j < nums.size(); j++) {
            res = (res + nums[j] * (y - 1) - x) % mod;
            x = (x * 2 + nums[j]) % mod;
            y = y * 2 % mod;
        }
        return (res + mod) % mod;
    }
};

// calculate the contributions of each item
class Solution {
public:
    static const int mod = 1e9 + 7;
    int sumSubseqWidths(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<long long> vpow(n, 1);
        for(int i = 1;i < n;++i) {
            vpow[i] = 2 * vpow[i - 1] % mod;
        }
        long long ans = 0LL;
        for(int i = 0;i < n;++i) {
            ans = (ans + vpow[i] * nums[i] - vpow[n - i - 1] * nums[i]) % mod;
        }
        return ans % mod;
    }
};