// 2022.11.29
class Solution {
public:
    int minOperations(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '0' + (i % 2)) {
                cnt++;
            }
        }
        return min(cnt, (int)s.size() - cnt);
    }
};