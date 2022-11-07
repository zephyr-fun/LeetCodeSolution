// 2022.11.07 update
class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        vector<vector<int>> a(2);
        vector<vector<int>> b(2);
        for(int i = 0; i < n; i++) {
            a[nums[i] % 2].emplace_back(nums[i]);
            b[target[i] % 2].emplace_back(target[i]);
        }
        for(int i = 0; i < 2; i++) {
            sort(a[i].begin(), a[i].end());
            sort(b[i].begin(), b[i].end());
        }
        long long res = 0;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < a[i].size(); j++) {
                if(a[i][j] > b[i][j]) {
                    res += (a[i][j] - b[i][j]) / 2;
                }
            }
        }
        return res;
    }
};