// 2022.03.31
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        vector<int> res(nums.size(), 0);
        int count = nums.size() - 1;
        while(left <= right){
            if(nums[left] * nums[left] < nums[right] * nums[right]){
                res[count--] = nums[right] * nums[right];
                right--;
            }
            else{
                res[count--] = nums[left] * nums[left];
                left++;
            }
        }
        return res;
    }
};