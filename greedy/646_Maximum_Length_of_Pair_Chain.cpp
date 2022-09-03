// 2022.09.03
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int res = 1;
        sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
            if(a[1] == b[1]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        int n = pairs.size();
        int prev = pairs[0][1];
        for(int i = 1; i < n; i++) {
            if(pairs[i][0] > prev) {
                res++;
                prev = pairs[i][1];
            }
        }
        return res;
    }
};