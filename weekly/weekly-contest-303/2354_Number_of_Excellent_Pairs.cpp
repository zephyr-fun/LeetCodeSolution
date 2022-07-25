// 2022.07.24
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        typedef long long LL;
        LL res = 0;
        // vector remove repeated
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        // vector remove repeated
        vector<int> cnt(30, 0);
        for(auto num : nums) {
            int temp = 0;
            while(num) {
                temp += (num & 1);
                num = num >> 1;
            }
            cnt[temp]++;
        }
        for(int i = 0; i < 30; i++) {
            for(int j = 0; j < 30; j++) {
                if(i + j >= k) {
                    res += (LL) cnt[i] * cnt[j];
                }
            }
        }
        return res;
    }
};