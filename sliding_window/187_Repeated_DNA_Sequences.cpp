// 2022.06.11
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        int n = s.size();
        vector<string> res;
        for(int i = 0; i <= n - 10; i++) {
            string temp = s.substr(i, 10);
            map[temp]++;
        }
        for(auto it : map) {
            if(it.second >= 2) {
                res.emplace_back(it.first);
            }
        }
        return res;
    }
};
