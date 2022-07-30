// 2022.07.30
class Solution {
public:
    void quick_sort(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return ;
        }
        int x = nums[(left + right) >> 1];
        int i = left - 1;
        int j = right + 1;
        while(i < j) {
            while(nums[++i] < x);
            while(nums[--j] > x);
            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }
        quick_sort(nums, left, j);
        quick_sort(nums, j + 1, right);
    }
    void sortColors(vector<int>& nums) {
        quick_sort(nums, 0, nums.size() - 1);
    }
};