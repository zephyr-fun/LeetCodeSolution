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