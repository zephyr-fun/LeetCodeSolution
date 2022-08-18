// 2022.08.18
class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(map.count(nums[i])) {
                freq[map[nums[i]]]--;
            }
            map[nums[i]]++;
            freq[map[nums[i]]]++;
            maxFreq = max(maxFreq, map[nums[i]]);
            bool ok = maxFreq == 1 || freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 || freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if(ok) {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};