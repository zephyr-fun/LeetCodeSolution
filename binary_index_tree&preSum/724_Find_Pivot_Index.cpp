// 2022.06.01
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int leftSum = 0;
        int rightSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            leftSum += nums[i];
            rightSum = sum - leftSum + nums[i];
            if(leftSum == rightSum) {
                return i;
            }
        }
        return -1;
    }
};

// 2022.06.17
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums) {
            sum += num;
        }
        int leftSum = 0;
        int rightSum = sum - nums[0];
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(leftSum == rightSum) {
                return i;
            }
            leftSum += nums[i];
            if(i + 1 < n) {
                rightSum -= nums[i + 1];
            }
        }
        return -1;
    }
};