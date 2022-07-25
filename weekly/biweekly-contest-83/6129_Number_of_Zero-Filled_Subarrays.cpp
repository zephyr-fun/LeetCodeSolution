// 2022.07.23
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res = 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        vector<int> part;
        while(right < n) {
            while(right < n && nums[left] != 0 && nums[right] != 0) {
                left++;
                right++;
            }
            while(right < n && nums[right] == 0) {
                right++;
            }
            if(right <= n) {
                part.emplace_back(right - left);
                left = right;
            }
        }
        for(auto p : part) {
            res += (long long) (p + 1) * p / 2;
        }
        return res;
    }
};