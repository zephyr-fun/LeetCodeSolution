// 2022.08.06 contest 2022.08.15 update
class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        unordered_map<long long, long long> map;
        for(int i = 0; i < n; i++) {
            // cout << nums[i] - i << endl;
            map[nums[i] - i]++;
            nums[i] = nums[i] - i;
        }
        // cout << n << endl;
        for(int i = 0; i < n - 1; i++) {
            // cout << i << n - i - 1 << map[nums[i]] - 1 << (n - i - 1) - (map[nums[i]] - 1) << endl;
            res += (n - i - 1) - (map[nums[i]] - 1);
            map[nums[i]]--;
        }
        return res;
    }
};