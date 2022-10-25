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

// 2022.10.05
// proof: 
// https://leetcode.cn/problems/container-with-most-water/solution/on-shuang-zhi-zhen-jie-fa-li-jie-zheng-que-xing-tu/
// https://leetcode.cn/problems/container-with-most-water/solution/shuang-zhi-zhen-fa-zheng-que-xing-zheng-ming-by-r3/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int left = 0;
        int right = n - 1;
        while(left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return res;
    }
};

// 2022.10.25
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int res = 0;
        while(left < right) {
            res = max(res, min(height[left], height[right]) * (right - left));
            if(height[left] > height[right]) {
                right--;
            }
            else {
                left++;
            }
        }
        return res;
    }
};