// 2022.05.18
// 2 dim binary search
class Solution {
public:
    int row, col, kth;
    int findKthNumber(int m, int n, int k) {
        row = min(m, n);
        col = max(m, n);
        kth = k;
        int left = 1;
        int right = m * n;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int val = getVal(mid);
            if(val >= k) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right + 1;
    }
    int getVal(int mid) {
        int a = 0;
        int b = 0;
        for(int i = 1; i <= row; i++) {
            if(i * col < mid) {
                a += col;
            }
            else {
                if(mid % i == 0 && ++b >= 0) {
                    a += mid / i - 1;
                }
                else {
                    a += mid / i;
                }
            }
        }
        return a + b;
    }
};