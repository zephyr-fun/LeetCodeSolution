// 2022.07.29
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if(i >= 0) {
            int j = n - 1;
            while(nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }
        reverse(nums.begin() + i + 1, nums.end());
    }
};

// 2022.10.06
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = n - 2;
        while(idx >= 0 && nums[idx] >= nums[idx + 1]) {
            idx--;
        }
        if(idx < 0) {
            reverse(nums.begin(), nums.end());
            return ;
        }
        int candi = n - 1;
        while(nums[candi] <= nums[idx]) {
            candi--;
        }
        swap(nums[idx], nums[candi]);
        sort(nums.begin() + idx + 1, nums.end());
    }
};