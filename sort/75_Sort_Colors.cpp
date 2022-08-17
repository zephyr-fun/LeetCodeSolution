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

// 2022.08.17
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

// double pointers
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int zero = 0;
        int two = n - 1;
        for(int i = 0; i <= two; i++) {
            while(i <= two && nums[i] == 2) {
                swap(nums[i], nums[two]);
                two--;
            }
            if(nums[i] == 0) {
                swap(nums[i], nums[zero]);
                zero++;
            }
        }
    }
};