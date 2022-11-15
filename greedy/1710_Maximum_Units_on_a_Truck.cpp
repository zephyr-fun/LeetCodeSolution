// 2022.11.15
class Solution {
public:
    int maximumUnits(vector<vector<int>>& bs, int k) {
        int n = bs.size();
        sort(bs.begin(), bs.end(), [] (auto& a, auto& b) {
            return a[1] > b[1];
        });
        int res = 0;
        for(int i = 0, cnt = 0; i < n && cnt < k; i++) {
            int a = bs[i][0];
            int b = bs[i][1];
            int c = min(a, k - cnt);
            res += b * c;
            cnt += c;
        }
        return res;
    }
};