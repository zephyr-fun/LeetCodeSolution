// 2023.02.13
// max(left_need, right_need)
class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int tot = 0;
        int n = machines.size();
        for(auto& m : machines) {
            tot += m;
        }
        if(tot % n != 0) {
            return -1;
        }
        int res = 0;
        int tar = tot / n;
        int left = 0;
        int right = tot;
        for(int i = 0; i < n; i++) {
            right -= machines[i];
            res = max(res, (left >= i * tar ? 0 : i * tar - left) + (right >= (n - 1 - i) * tar ? 0 : (n - 1 - i) * tar - right));
            left += machines[i];
        }
        return res;
    }
};