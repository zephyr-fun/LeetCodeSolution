// 2022.06.05
// recursion
class Solution {
public:
    int recursion(vector<int>& nums, bool mode) {
        if(nums.size() == 2) {
            if(mode) {
                return min(nums[0], nums[1]);
            }
            else {
                return max(nums[0], nums[1]);
            }
        }
        else {
            int size = nums.size();
            vector<int> left(nums.begin(), nums.begin() + size / 2);
            vector<int> right(nums.begin() + size / 2, nums.end());
            if(mode) {
                return min(recursion(left, true), recursion(right, false));
            }
            else {
                return max(recursion(left, true), recursion(right, false));
            }
        }
        return -1;
    }
    int minMaxGame(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        return recursion(nums, true);
    }
};

// 2023.01.15
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        queue<int> que;
        bool is_min = true;
        for(auto& num : nums) {
            que.push(num);
        }
        while(que.size() > 1) {
            int size = que.size();
            is_min = true;
            for(int i = 0; i < size; i += 2) {
                int first = que.front();
                que.pop();
                int second = que.front();
                que.pop();
                if(is_min) {
                    que.push(min(first, second));
                }
                else {
                    que.push(max(first, second));
                }
                is_min = !is_min;
            }
            
        }
        return que.front();
    }
};

// 2023.01.15
class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        for(int n = nums.size(); n > 1; ) {
            n >>= 1;
            for(int i = 0; i < n; i++) {
                int a = nums[i << 1];
                int b = nums[i << 1 | 1];
                nums[i] = i % 2 == 0 ? min(a, b) : max(a, b);
            }
        }
        return nums[0];
    }
};