// 2022.05.19
// find mid;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = nums[nums.size() / 2];
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res += abs(nums[i] - mid);
        }
        return res;
    }
};
// optim
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int res = 0;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            res += nums[right--] - nums[left++];
        }
        return res;
    }
};