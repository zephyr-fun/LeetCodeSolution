// 2022.08.26
class Solution {
public:
    void quick_sort(vector<int>& nums, int left, int right) {
        if(left >= right) {
            return ;
        }
        int i = left - 1;
        int j = right + 1;
        int x = nums[(left + right) >> 1];
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
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        quick_sort(nums, 0, n - 1);
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};