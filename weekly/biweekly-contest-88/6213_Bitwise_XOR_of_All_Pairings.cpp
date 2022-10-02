// 2022.10.01
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int res = 0;
        int n = nums1.size();
        int m = nums2.size();
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        for(auto& num : nums1) {
            map1[num]++;
        }
        for(auto& num : nums2) {
            map2[num]++;
        }
        for(auto [k, v] : map1) {
            if(((long long)v * (long long)m) % 2) {
                res ^= k;
            }
        }
        for(auto [k, v] : map2) {
            if(((long long)v * (long long)n) % 2) {
                res ^= k;
            }
        }
        return res;
    }
};