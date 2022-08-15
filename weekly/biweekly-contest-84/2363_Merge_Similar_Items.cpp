// 2022.08.06 contest 2022.08.15 update
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> map;
        for(auto it : items1) {
            map[it[0]] += it[1];
        }
        for(auto it : items2) {
            map[it[0]] += it[1];
        }
        vector<vector<int>> res;
        for(auto [k, v] : map) {
            vector<int> temp(initializer_list<int>{k, v});
            res.emplace_back(temp);
        }
        sort(res.begin(), res.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        return res;
    }
};