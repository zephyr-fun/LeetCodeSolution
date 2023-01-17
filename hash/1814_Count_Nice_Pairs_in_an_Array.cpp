// 2023.01.17
class Solution {
public:
    int reverse(int num) {
        int res = 0;
        while(num) {
            res *= 10;
            res += num % 10;
            num /= 10;
        }
        return res;
    }
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9 + 7;
        unordered_map<int, int> map;
        int res = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int rever = reverse(nums[i]);
            int target = nums[i] - rever;
            res = (res + map[target]) % mod;
            map[target]++;
        }
        return res;
    }
};