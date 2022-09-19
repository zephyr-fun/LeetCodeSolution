// 2022.09.19
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> map;
        for(auto& num : nums) {
            map[num]++;
        }
        vector<vector<int>> temp;
        for(auto& [k, v] : map) {
            temp.emplace_back(initializer_list<int>({k, v}));
        }
        sort(temp.begin(), temp.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        vector<int> res;
        for(auto& t : temp) {
            for(int i = 0; i < t[1]; i++) {
                res.emplace_back(t[0]);
            }
        }
        return res;
    }
};