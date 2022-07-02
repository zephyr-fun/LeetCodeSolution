// 2022.07.02
class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        // 1 or 9, can't change anything
        if(nums.size() <= 1) {
            return -1;
        }
        // find the first reverse order position
        int i = nums.size() - 2;
        while(i >= 0) {
            if(nums[i] < nums[i + 1]) {
                break;
            }
            i--;
        }
        // 987654321, can't change anything
        if(i < 0) {
            return -1;
        }
        // find the first position that greater than nums[i](swap position)
        int j = nums.size() - 1;
        while(j >= 0) {
            if(nums[j] > nums[i]) {
                break;
            }
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        // avoid int overflow
        long res = stol(nums);
        return res > INT_MAX ? -1 : res;
    }
};