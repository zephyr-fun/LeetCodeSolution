// 2022.07.28
class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        unordered_map<int, vector<int>> map;
        for(int i = 0; i < n; i++) {
            map[arr[i]].emplace_back(i);
        }
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        for(int i = 0; i < arr.size(); i++) {
            for(auto pos : map[arr[i]]) {
                res[pos] = i + 1;
            }
        }
        return res;
    }
};