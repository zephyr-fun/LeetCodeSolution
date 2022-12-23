// 2022.12.23
// hash
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int target = nums.size() / 2;
        unordered_map<int, int> map;
        for(auto& num : nums) {
            map[num]++;
            if(map[num] > target) {
                return num;
            }
        }
        return -1;
    }
};

// optim
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cur = 0;
        int cnt = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                cur = nums[i];
                cnt = 1;
            }
            else if(nums[i] == cur) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return cur;
    }
};