// 2023.05.11
// 0x3f version
// https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/solution/san-chong-suan-fa-cong-bao-li-dao-you-hu-nmtq/
class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> seen;
        for(int i = 0, m = s.size(); i < m; i++) {
            int x = s[i] - '0';
            if(x == 0) {
                continue;
            }
            for(int j = i + 1; x <= n; j++) {
                seen.insert(x);
                if(j == m) {
                    break;
                }
                x = (x << 1) | (s[j] - '0');
            }
        }
        return seen.size() == n;
    }
};