// 2022.08.12
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> map;
        vector<vector<int>> res;
        for(int i = 0; i < groupSizes.size(); i++) {
            int group = groupSizes[i];
            map[group].emplace_back(i);
            if(map[group].size() == group) {
                res.emplace_back(map[group]);
                map[group].clear();
            }
        }
        // sort(res.begin(), res.end(), []({
        //     return a.size() < b.size();
        // });
        return res;
    }
};