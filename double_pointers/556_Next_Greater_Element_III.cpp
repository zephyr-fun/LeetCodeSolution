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

// 2022.07.03
class Solution {
public:
    int nextGreaterElement(int n) {
        string nums = to_string(n);
        int i = nums.size() - 2;
        int j = nums.size() - 1;
        while(i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        if(i < 0) {
            return -1;
        }
        while(j >= 0 && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        long res = stol(nums);
        return res > INT_MAX ? -1 : res;
    }
};

// 2022.09.14
class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int cnt = num.size();
        int idx = cnt - 2;
        while(idx >= 0) {
            if(num[idx] < num[idx + 1]) {
                break;
            }
            idx--;
        }
        if(idx < 0) {
            return -1;
        }
        int temp = cnt - 1;
        while(temp >= 0 && num[idx] >= num[temp]) {
            temp--;
        }
        swap(num[idx], num[temp]);
        reverse(num.begin() + idx + 1, num.end());
        return stol(num) > INT_MAX ? -1 : stol(num);
    }
};

// 2022.10.10
// greedy
class Solution {
public:
    int nextGreaterElement(int n_) {
        string num = to_string(n_);
        int n = num.size();
        int idx = n - 2;
        while(idx >= 0 && num[idx] >= num[idx + 1]) {
            idx--;
        }
        if(idx < 0) {
            return -1;
        }
        int candi = n - 1;
        while(candi > idx && num[candi] <= num[idx]) {
            candi--;
        }
        swap(num[candi], num[idx]);
        sort(num.begin() + idx + 1, num.end());
        long res = stol(num);
        return res > INT_MAX ? -1 : res;
    }
};