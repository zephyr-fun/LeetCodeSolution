// 2023.03.25
// endlesscheng version
// https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/solution/dong-hua-yi-xie-jiu-cuo-liang-chong-xie-iijwz/
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while(right && arr[right - 1] <= arr[right]) {
            right--;
        }
        if(!right) {
            return 0;
        }
        int res = right;
        for(; left == 0 || arr[left - 1] <= arr[left]; left++) {
            while(right < n && arr[right] < arr[left]) {
                right++;
            }
            res = min(res, right - left - 1);
        }
        return res;
    }
};