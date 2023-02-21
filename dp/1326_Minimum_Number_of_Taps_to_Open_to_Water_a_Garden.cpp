// 2023.02.21
class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        int right_most[n + 1];
        memset(right_most, 0, sizeof(right_most));
        for(int i = 0; i <= n; i++) {
            int r = ranges[i];
            if(i > r) {
                right_most[i - r] = i + r;
            }
            else {
                right_most[0] = max(right_most[0], i + r);
            }
        }
        int res = 0;
        int cur_right = 0;
        int next_most_right = 0;
        for(int i = 0; i < n; i++) {
            next_most_right = max(next_most_right, right_most[i]);
            if(i == cur_right) {
                if(i == next_most_right) {
                    return -1;
                }
                cur_right = next_most_right;
                res++;
            }
        }
        return res;
    }
};