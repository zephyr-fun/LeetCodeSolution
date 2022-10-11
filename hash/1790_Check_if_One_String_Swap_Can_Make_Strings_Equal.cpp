// 2022.10.11
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int pos1 = -1;
        int pos2 = -1;
        int n = s1.size();
        for(int i = 0; i < n; i++) {
            if(s1[i] == s2[i]) {
                continue;
            }
            if(pos1 == -1) {
                pos1 = i;
            }
            else if(pos2 == -1) {
                pos2 = i;
            }
            else {
                return false;
            }
        }
        if(pos1 == pos2 && pos1 == -1) {
            return true;
        }
        if(pos1 == -1 || pos2 == -1) {
            return false;
        }
        return s1[pos1] == s2[pos2] && s1[pos2] == s2[pos1];
    }
};