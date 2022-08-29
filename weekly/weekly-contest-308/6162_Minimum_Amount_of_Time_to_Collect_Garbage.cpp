// 2022.08.29 sorted
class Solution {
public:
    int garbageCollection(vector<string>& g, vector<int>& t) {
        int n = g.size();
        unordered_map<char, int> cnt;
        unordered_map<char, int> map;
        for(int i = 0; i < n; i++) {
            for(auto& c : g[i]) {
                map[c] = i;
                cnt[c]++;
            }
        }
        int res = 0;
        vector<int> presum(n, 0);
        for(int i = 1; i < n; i++) {
            presum[i] = t[i - 1] + presum[i - 1];
        }
        for(auto& [k, v] : map) {
            // cout << k << v << endl;
            res += cnt[k];
            res += presum[v];
        }
        return res;
    }
};