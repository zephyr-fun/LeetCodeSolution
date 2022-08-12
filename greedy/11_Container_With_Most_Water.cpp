// 2022.08.12
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        while(left < right) {
            res = max(res, (right - left) * min(height[left], height[right]));
            height[left] < height[right] ? left++ : right--;
        }
        return res;
    }
};