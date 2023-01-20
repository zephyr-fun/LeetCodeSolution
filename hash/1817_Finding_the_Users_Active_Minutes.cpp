// 2023.01.20
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> map;
        vector<int> res(k, 0);
        for(auto& log : logs) {
            int id = log[0];
            int mins = log[1];
            map[id].insert(mins);
        }
        for(auto [id, s] : map) {
            if(s.size() <= k)
            res[s.size() - 1]++;
        }
        return res;
    }
};