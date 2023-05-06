// 2023.05.06
class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        char previous['s'];
        const string croak = "croakc";
        for(int i = 1; i < croak.size(); i++) {
            previous[croak[i]] = croak[i - 1];
        }
        int cnt['s']{}; // same as unordered_map<string, int>
        for(char c : croakOfFrogs) {
            char pre = previous[c];
            if(cnt[pre]) {
                cnt[pre]--;
            }
            else if(c != 'c') {
                return -1;
            }
            cnt[c]++;
        }
        if(cnt['c'] || cnt['r'] || cnt['o'] || cnt['a']) {
            return -1;
        }
        return cnt['k'];
    }
};