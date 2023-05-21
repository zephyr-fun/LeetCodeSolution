// 2023.05.21
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int mx = *max_element(vat.begin(), vat.end());
        if(mx == 0) {
            return 0;
        }
        int n = vat.size();
        int res = 0x3f3f3f3f;
        // 枚举浇水次数 x
        for(int x = 1; x <= mx; x++) {
            int y = 0;
            for(int i = 0; i < n; i++) {
                // 统计升级水桶次数 y
                y += max(0, (vat[i] + x - 1) / x - bucket[i]);
            }
            res = min(res, x + y);
        }
        return res;
    }
};