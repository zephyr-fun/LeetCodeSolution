// 2022.06.11
// prefix sum
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n + 2, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] - '0');
        }
        prefix[n + 1] = prefix[n];
        int res = 0x3f3f3f3f;
        for(int i = 1; i <= n + 1; i++) {
            int zero = prefix[i - 1] - prefix[0];
            int one = (n - i + 1) - (prefix[n] - prefix[i - 1]);
            // cout << zero << '|' << one << endl;
            res = min(res, zero + one);
        }
        return res;
    }
};