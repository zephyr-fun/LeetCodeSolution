// 2022.08.15
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> nums;
        int n = words.size();
        for(auto& word : words) {
            int temp = 0;
            for(auto& c : word) {
                int cur = c - 'a';
                temp |= (1 << cur);
            }
            nums.emplace_back(temp);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if((nums[i] & nums[j]) == 0) {
                    res = max(res, (int)words[i].size() * (int)words[j].size());
                }
            }
        }
        return res;
    }
};