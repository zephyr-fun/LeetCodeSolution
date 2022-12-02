// 2022.12.02
// vector<int> slow
class Solution {
public:
    int characterReplacement(string s, int k) {
        // int cnt[26];
        // memset(cnt, 0, sizeof(cnt));
        vector<int> cnt(26, 0);
        int res = 0;
        int n = s.size();
        for(int l = 0, r = 0; r < n; r++) {
            cnt[s[r] - 'A']++;
            while(!check(cnt, k)) {
                cnt[s[l] - 'A']--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
    bool check(vector<int>& cnt, int k) { // int cnt[]
        int maxVal = 0;
        int sum = 0;
        for(int i = 0; i < 26; i++) {
            maxVal = max(maxVal, cnt[i]);
            sum += cnt[i];
        }
        return sum - maxVal <= k;
    }
};