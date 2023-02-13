// 2023.02.13
class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int m = n / 4;
        int cnt['X']{};
        for(auto& c : s) {
            cnt[c]++;
        }
        if(cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int res = 0x3f3f3f3f;
        while(right < n) {
            cnt[s[right]]--;
            right++;
            while(left < right && cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                res = min(res, right - left);
                ++cnt[s[left++]];
            }
        }
        return res;
    }
};