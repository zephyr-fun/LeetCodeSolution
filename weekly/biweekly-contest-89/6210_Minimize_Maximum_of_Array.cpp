// 2022.10.15
// https://leetcode.cn/circle/discuss/7RMPmn/
// TsReaper version
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        for(int x : nums) {
            mx = max(mx, x);
        }
        int head = 0;
        int tail = mx;
        while(head < tail) {
            int mid = (head + tail) >> 1;
            vector<long long> A;
            for(int x : nums) {
                A.push_back(x);
            }
            for(int i = n - 1; i > 0; i--) {
                if (A[i] > mid) {
                    long long det = A[i] - mid;
                    A[i] = mid;
                    A[i - 1] += det;
                }
            } 
            if (A[0] <= mid) {
                tail = mid;
            }
            else {
               head = mid + 1; 
            }
        }
        return head;
    }
};