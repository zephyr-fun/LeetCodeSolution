// 2023.06.13
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int num : nums) {
            map[num]++;
        }
        int a = 0;
        int b = 0;
        int c = nums.size();
        int res = 0;
        for(auto& [k, v] : map) {
            b = v;
            c -= b;
            res += a * b * c;
            a += b;
        }
        return res;
    }
};