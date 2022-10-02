// 2022.10.02
class Solution {
public:
    bool canTransform(string start, string end) {
        string s = "";
        string e = "";
        for(auto& ss : start) {
            if(ss != 'X') {
                s += ss;
            }
        }
        for(auto& ss : end) {
            if(ss != 'X') {
                e += ss;
            }
        }
        if(s != e) {
            return false;
        }
        for(int i = 0, j = 0; i < start.size(); i++) {
            if(start[i] == 'X') {
                continue;
            }
            while(end[j] == 'X') {
                j++;
            }
            if(i != j && (start[i] == 'L') != (i > j)) {
                return false;
            }
            j++;
        }
        return true;
    }
};