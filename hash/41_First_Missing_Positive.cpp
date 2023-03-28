// 2022.10.20
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            while(nums[i] != i + 1) {
                if(nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1]) { // loop for the last one
                    break;
                }
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};

// 2023.03.28
// 原地哈希，规则是nums[i] = i + 1
// 相当于对于每一个容器位置 i ，尽可能地让其中所存储的内容是 i + 1
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            // 相当于对于每一个容器位置 i ，尽可能地让其中所存储的内容是 i + 1
            while(nums[i] != i + 1) {
                // 但是当内容需要的位置不在1->n之内的话，就只能作罢
                if(nums[i] <= 0 || nums[i] > n || nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                int idx = nums[i] - 1;
                nums[i] = nums[idx];
                nums[idx] = idx + 1;
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};