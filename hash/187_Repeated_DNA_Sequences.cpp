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

// 2022.06.27
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> map;
        vector<string> res;
        if(s.size() < 10) {
            return res;
        }
        for(int i = 0; i <= s.size() - 10; i++) {
            string temp = s.substr(i, 10);
            map[temp]++;
        }
        for(auto [k, v] : map) {
            if(v > 1) {
                res.emplace_back(k);
            }
        }
        return res;
    }
};

// 2022.08.19
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> res;
        unordered_map<string, int> map;
        for(int i = 0; i <= n - 10; i++) {
            string temp = s.substr(i, 10);
            map[temp]++;
            if(map[temp] == 2) {
                res.emplace_back(temp);
            }
        }
        return res;
    }
};