// 2022.06.25
// ingenious, actually this is dp too
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) {
            return 0;
        }
        int tot = 0;
        int diff = nums[0] - nums[1];
        int res = 0;
        for(int i = 2; i < n; i++) { // find out if nums[i] can concate to the prev subarray
            if(nums[i - 1] - nums[i] == diff) {
                tot++;
            }
            else {
                tot = 0;
                diff = nums[i - 1] - nums[i];
            }
            res += tot;
        }
        return res;
    }
};

// dp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int dp = 0;
        int res = 0;
        for(int i = 2; i < n; i++) {
            dp = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp + 1 : 0;
            res += dp;
        }
        return res;
    }
};

// 2022.10.01
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int dp = 0;
        int res = 0;
        for(int i = 2; i < n; i++) {
            dp = nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2] ? dp + 1 : 0;
            res += dp;
        }
        return res;
    }
};