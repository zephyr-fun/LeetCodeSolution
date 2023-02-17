// 2022.08.14
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        vector<int> ones(n, 0);
        ones[n - 1] = 0;
        for(int i = n - 1; i >= 1; i--) {
            ones[i - 1] = ones[i] + (s[i] == '1' ? 1 : 0);
            // cout << i - 1 << "ones" << ones[i - 1] << endl;
        }
        int zero = 0;
        int res = 0;
        for(int i = 0; i < n - 1; i++) {
            zero += s[i] == '0' ? 1 : 0;
            res = max(res, zero + ones[i]);
        }
        return res;
    }
};