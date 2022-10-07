// 2022.10.07
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        int map[n + 1];
        memset(map, 0, sizeof(map));
        for(int i = 0; i < n; i++) {
            map[nums[i]]++;
        }
        vector<int> res;
        for(int i = 1; i <= n; i++) {
            if(map[i] == 0) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// inplace hash
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[(nums[i] - 1) % n] += n;
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if(nums[i] <= n) {
                res.emplace_back(i + 1);
            }
        }
        return res;
    }
};