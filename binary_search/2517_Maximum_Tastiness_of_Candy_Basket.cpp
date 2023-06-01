// 2023.06.01
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        function<int(int)> check = [&] (int d) -> int {
            int cnt = 1;
            int x0 = price[0];
            for(int x : price) {
                if(x >= x0 + d) {
                    cnt++;
                    x0 = x;
                }
            }
            return cnt;
        };

        int left = 0;
        int right = (price.back() - price[0]) / (k - 1) + 1;
        while(left + 1 < right) {
            int mid = left + (right - left) / 2;
            (check(mid) >= k ? left : right) = mid;
        }
        return left;
    }
};