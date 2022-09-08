// 2022.09.08
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int idx = 0;
        vector<int> res(n, 0);
        int left = 1;
        int right = n;
        for(int i = 0; i < k; i++) {
            if(i & 1) {
                res[idx++] = right--;
            }
            else {
                res[idx++] = left++;
            }
        }
        if(idx & 1) {
            while(idx < n) {
                res[idx++] = left++;
            }
        }
        else {
            while(idx < n) {
                res[idx++] = right--;
            }
        }
        return res;
    }
};