// 2022.10.16
// https://blog.csdn.net/Jakon_/article/details/124226206
// https://www.bilibili.com/video/BV1aZ4y127kG/?spm_id_from=333.337.search-card.all.click&vd_source=1e5e0fe23d3d704a3f15a4928671d9ac
#include <bits/stdc++.h>
const int N = 200010;
long long n, x, y, a[N], ans;
class Solution {
public:
    long long cal(int l, int r)
    {
        long long res = 0, s = 1, t = 1;
        for(int i = 1; i <= n; i++) {
            if(a[i] >= l && a[i] <= r) s = t = i;
            else continue;
            while(a[t] >= l && a[t] <= r && t <= n) ++ t;
            res += (long long)(t - s) * (long long)(t - s + 1) / 2;
            i = t - 1;
        }
        return res;
        
    }

    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        n = nums.size();
        x = maxK;
        y = minK;
        for(int i = 1; i <= n; i++) {
            a[i] = nums[i - 1];
        }
        ans = cal(y, x) - cal(y + 1, x) - cal(y, x - 1) + cal(y + 1, x - 1);
        return ans;
    }
};