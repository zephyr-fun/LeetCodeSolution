// 2022.09.14
class Solution {
public:
    double trimMean(vector<int>& arr) {
        double res = 0;
        int n = arr.size();
        int cnt = (int)((double)n * 0.05);
        sort(arr.begin(), arr.end());
        for(int i = cnt; i < n - cnt; i++) {
            res += arr[i];
        }
        return res / (n - 2 * cnt);
    }
};