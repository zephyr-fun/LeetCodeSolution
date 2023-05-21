// 2022.11.24
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int res = 0;
        int i0 = -1;
        int i1 = -1;
        for(int i = 0; i < n; i++) {
            if(nums[i] > right) {
                i0 = i;
            }
            if(nums[i] >= left) {
                i1 = i;
            }
            res += i1 - i0;
        }
        return res;
    }
};

// 2023.05.21
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size();
        int i0 = -1; // 上一个最近的不能取的大于right的位置
        int i1 = -1; // 上一个最近的一定要取的在left和right之间的最大值的位置
        // i1和i0之间维护的就是对于当前枚举的右端点来说可行的左端点区间，累加即为答案
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > right) {
                i0 = i;
            }
            if(nums[i] >= left) {
                i1 = i;
            }
            res += i1 - i0;
        }
        return res;
    }
};