// 2023.10.10
class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = nums[i] * 1LL + (s[i] == 'R' ? d : -d);
        }
        sort(arr.begin(), arr.end());
        long long res = 0;
        long long sum = 0;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            res = (res + arr[i] * i - sum) % mod;
            sum += arr[i];
        }
        return res;
    }
};