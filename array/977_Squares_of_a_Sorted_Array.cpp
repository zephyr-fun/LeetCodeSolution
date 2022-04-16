// 2022.04.16
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(nums.size());
        int index = nums.size() - 1;
        while(left <= right){
            if(abs(nums[left]) <= abs(nums[right])) {
                res[index] = nums[right] * nums[right];
                right--;
                index--;
            }
            else {
                res[index] = nums[left] * nums[left];
                left++;
                index--;
            }
        }
        return res;
    }
};