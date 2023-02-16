// 2023.02.16
class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto& num : nums) {
            map[num]++;
        }
        int p = 0;
        int s = 0;
        for(auto [num, cnt] : map) {
            p += cnt / 2;
            s += cnt % 2;
        }
        return {p, s};
    }
};