// 2023.01.30
// https://leetcode.cn/problems/count-increasing-quadruplets/solution/you-ji-qiao-de-mei-ju-yu-chu-li-pythonja-exja/
class Solution {
    int great[4000][4001];
public:
    long long countQuadruplets(vector<int> &nums) {
        int n = nums.size();
        int less[n + 1];
        for(int k = n - 2; k >= 2; k--) {
            memcpy(great[k], great[k + 1], sizeof(great[k + 1]));
            for(int x = nums[k + 1] - 1; x > 0; x--) {
                great[k][x]++; // x < nums[k+1]，对于 x，大于它的数的个数 +1, great[k][x] 在k右边比x大的数的个数
            }
        }

        long res = 0;
        memset(less, 0, sizeof(less));
        for(int j = 1; j < n - 2; j++) {
            for(int x = nums[j - 1] + 1; x <= n; x++) {
                less[x]++; // x > nums[j-1]，对于 x，小于它的数的个数 +1, less[x] 在j左边比x小的数的个数
            }
            for(int k = j + 1; k < n - 1; k++) {
                if(nums[j] > nums[k]) {
                    res += less[nums[k]] * great[k][nums[j]];
                }
            }
        }
        return res;
    }
};