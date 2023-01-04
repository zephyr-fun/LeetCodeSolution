// 2023.01.04
class Solution {
public:
    int idx;
    int n;
    long long calc(int maxVal) {
        long long left = 0;
        long long right = 0;
        if(maxVal >= idx + 1) {
            left = (2 * (long long)maxVal - idx) * (idx + 1) / 2;
        }
        else {
            left = idx + 1 - maxVal + (1 + (long long)maxVal) * maxVal / 2;
        }
        if(maxVal >= n - idx) {
            right = (2 * (long long)maxVal - n + idx) * (n - idx - 1) / 2;
        }
        else {
            right = n - idx - maxVal + (1 + (long long)maxVal - 1) * (maxVal - 1) / 2;
        }
        return left + right;
    }
    int maxValue(int _n, int _index, int maxSum) {
        n = _n;
        idx = _index;
        int left = 1;
        int right = maxSum;
        int pos = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            long long temp = calc(mid);
            if(temp > maxSum) {
                right = mid - 1;
            }
            else {
                pos = mid;
                left = mid + 1;
            }
        }
        return pos;
    }
};