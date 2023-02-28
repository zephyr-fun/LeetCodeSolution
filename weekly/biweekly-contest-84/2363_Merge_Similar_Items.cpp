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

// 2023.02.28
class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        unordered_map<int, int> map;
        for(auto& item : items1) {
            map[item[0]] += item[1];
        }
        for(auto& item : items2) {
            map[item[0]] += item[1];
        }
        vector<vector<int>> res;
        for(auto& [k, v] : map) {
            res.push_back({k, v});
        }
        sort(res.begin(), res.end(), [] (vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });
        return res;
    }
};