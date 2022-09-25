// 2022.09.25
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        unordered_map<int, string> map;
        int idx = 0;
        for(auto& height : heights) {
            map[height] = names[idx];
            idx++;
        }
        sort(heights.begin(), heights.end(), [](int& a, int& b) {
            return a > b;
        });
        vector<string> res;
        for(auto& height : heights) {
            res.emplace_back(map[height]);
        }
        return res;
    }
};