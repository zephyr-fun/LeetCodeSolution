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

// 2022.04.19
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        int left = 0;
        int right = nums.size() - 1;
        int count = nums.size() - 1;
        while(left <= right) {
            if(abs(nums[left]) > abs(nums[right])) {
                res[count] = nums[left] * nums[left];
                left++;
            }
            else {
                res[count] = nums[right] * nums[right];
                right--;
            }
            count--;
        }
        return res;
    }
};