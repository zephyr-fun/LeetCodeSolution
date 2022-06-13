// 2022.06.13
class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int sn = s.size();
        int subn = sub.size();
        unordered_map<char, unordered_set<char>> map;
        for(auto mapping : mappings) {
            char a = mapping[0];
            char b = mapping[1];
            map[a].insert(b);
        }
        for(int i = 0; i < sn; i++) {
            if(sn - i < subn) {
                break;
            }
            bool ok = true;
            for(int j = i; j < i + subn; j++) {
                int k = j - i;
                char x = s[j];
                char y = sub[k];
                if(x != y) {
                    if(map.find(y) != map.end() && map[y].find(x) != map[y].end()) {
                        continue;
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
            }
            if(ok == true) {
                return true;
            }
        }
        return false;
    }
};