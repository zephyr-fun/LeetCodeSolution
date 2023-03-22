// 2023.03.22
// 和最长上升子序列不一样的是，这里的目标是求最大值，而非最长值，所以二分 LIS 中的贪心更新 dp[len] 是不能用的
// 除非序列中没有重复值，也就是最长值和最大值退化到一致
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> dp(n + 1, 0);
        int len = 0;
        // unordered_map<int, int> map;
        // for(int i = 0; i < n; i++) {
        //     map[ages[i]] = i;
        // }
        // sort(ages.begin(), ages.end(), [&] (int& a, int& b) {
        //     if(a == b) {
        //         return scores[map[a]] < scores[map[b]];
        //     }
        //     return a < b;
        // });
        pair<int, int> a[n];
        for(int i = 0; i < n; i++) {
            a[i] = {ages[i], scores[i]};
        }
        sort(a, a + n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(a[i].second > dp[len] || (i != 0 && a[i - 1].first == a[i].first)) {
                len++;
                dp[len] = a[i].second;
                res = max(res, accumulate(dp.begin(), dp.begin() + len + 1, 0));
            }
            else {
                int left = 0;
                int right = len - 1;
                int pos = 0;
                while(left <= right) {
                    int mid = (left + right) >> 1;
                    if(dp[mid] < a[i].second) {
                        pos = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                dp[pos + 1] = min(dp[pos + 1], a[i].second);
            }
        }
        return res;
    }
};

// O(n^2)
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<int> dp(n + 1, 0);
        int len = 0;
        pair<int, int> a[n];
        for(int i = 0; i < n; i++) {
            a[i] = {ages[i], scores[i]};
        }
        sort(a, a + n);
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(a[j].second <= a[i].second) {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += a[i].second;
            res = max(dp[i], res);
        }
        return res;
    }
};