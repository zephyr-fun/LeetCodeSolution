// 2022.09.08
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> smap;
        unordered_map<char, char> tmap;
        int n = s.size();
        for(int i = 0; i < n; i++) {
            if(!smap.count(s[i]) && !tmap.count(t[i])) {
                smap[s[i]] = t[i];
                tmap[t[i]] = s[i];
            }
            else {
                if(smap[s[i]] != t[i] || tmap[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};