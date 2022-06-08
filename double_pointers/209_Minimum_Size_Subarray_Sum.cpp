// 2022.03.25
// Sliding Window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int res = INT_MAX;
        int i = 0;
        int subLength = 0;
        for(int j = 0; j < nums.size(); j++){
            sum += nums[j];
            while(sum >= target){
                subLength = j - i + 1;
                res = res < subLength ? res : subLength;
                sum -= nums[i];
                i++;
            }
        }
        return res == INT_MAX ? 0 : res;
    }
};

// 2022.04.16
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int res = INT_MAX;
        while(right < nums.size()){
            sum += nums[right];
            while(sum >= target){
                res = res < right - left + 1 ? res : right - left + 1;
                sum -= nums[left];
                left++;
            }
            right++;
        }
        return res == INT_MAX ? 0 : res;
    }
};

// 2022.06.08
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int n = nums.size();
        int sum = 0;
        int res = 0x3f3f3f3f;
        while(right < n) {
            sum += nums[right];
            right++;
            while(sum - nums[left] >= target) {
                sum -= nums[left];
                left++;
            }
            if(sum >= target) {
                res = min(res, right - left);
            }
            
        }
        return res == 0x3f3f3f3f ? 0 : res;
    }
};