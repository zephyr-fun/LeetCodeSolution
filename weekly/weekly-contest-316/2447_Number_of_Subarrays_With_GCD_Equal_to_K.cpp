// 2022.11.07 update
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] % k != 0) {
                continue;
            }
            int cur = nums[i];
            for(int j = i; j < n; j++) {
                if(nums[j] % k != 0) {
                    break;
                }
                cur = min(cur, gcd(cur, nums[j]));
                if(cur == k) {
                    res++;
                }
            }
        }
        return res;
    }
};