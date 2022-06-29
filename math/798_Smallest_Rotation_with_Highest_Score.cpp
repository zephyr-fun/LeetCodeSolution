// 2022.06.10
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            int bound1 = (i - (n - 1) + n) % n;
            int bound2 = (i - nums[i] + n) % n;
            if(bound1 <= bound2) {
                diff[bound1]++;
                diff[bound2 + 1]--;
            }
            else {
                diff[bound1]++;
                diff[n]--;
                diff[0]++;
                diff[bound2 + 1]--;
            }
        }
        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(diff[i] > diff[res]) {
                res = i;
            }
        }
        return res;
    }
};

//https://leetcode.cn/problems/smallest-rotation-with-highest-score/solution/gong-shui-san-xie-shang-xia-jie-fen-xi-c-p6kh/
// 对于每一个i，确定下能够使它得分的k的区间，标记下来（使用差分数组），然后取最大累积的k的值
// 2022.06.29
class Solution {
public:
    int bestRotation(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n + 1, 0);
        int res = 0;
        for(int i = 0; i < n; i++) {
            int lower = (i - (n - 1) + n) % n;
            int upper = (i - nums[i] + n) % n;
            if(lower <= upper) {
                diff[lower]++;
                diff[upper + 1]--;
            }
            else {
                diff[lower]++;
                diff[n]--;
                diff[0]++;
                diff[upper + 1]--;
            }
        }
        for(int i = 1; i < n; i++) {
            diff[i] += diff[i - 1];
        }
        for(int i = 0; i < n; i++) {
            if(diff[i] > diff[res]) {
                res = i;
            }
        }
        return res;
    }
};