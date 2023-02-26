// 2023.02.26
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> cnt0, cnt1;
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                cnt1[nums[i]]++;
            }
            else {
                cnt0[nums[i]]++;
            }
        }
        auto getMax2 = [] (unordered_map<int, int>& hash) {
            vector<pair<int, int>> res;
            for(auto [k, v] : hash) {
                res.emplace_back(make_pair(k, v));
            }
            sort(res.begin(), res.end(), [] (pair<int, int>& a, pair<int, int>& b) {
                return a.second > b.second;
            });
            res.resize(2);
            return res;
        };
        auto a0 = getMax2(cnt0);
        auto a1 = getMax2(cnt1);
        if(a0[0].first != a1[0].first) {
            return n - a0[0].second - a1[0].second;
        }
        return n - max(a0[0].second + a1[1].second, a0[1].second + a1[0].second);
    }
};