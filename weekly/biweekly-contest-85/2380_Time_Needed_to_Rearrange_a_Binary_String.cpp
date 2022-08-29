// 2022.08.29 sorted
class Solution {
public:
    bool check(string& s) {
        for(int i = 1; i < s.size(); i++) {
            if(s[i - 1] == '0' && s[i] == '1') {
                return false;
            }
        }
        return true;
    }
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        int res = 0;
        while(!check(s)) {
            for(int i = 1; i < n; i++) {
                if(s[i - 1] == '0' && s[i] == '1') {
                    s[i - 1] = '1';
                    s[i] = '0';
                    i++;
                }
            }
            res++;
        }
        return res;
    }
};