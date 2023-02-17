// 2022.09.24
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> preSum;
        preSum.emplace_back(0);
        int n = code.size();
        vector<int> res(n, 0);
        if(k == 0) {
            return res;
        }
        for(int i = 0; i < 3 * n; i++) {
            preSum.emplace_back(preSum.back() + code[i % n]);
        }
        
        for(int i = n; i < 2 * n; i++) {
            if(k > 0) {
                res[i % n] = preSum[i + k + 1] - preSum[i + 1];
            }
            else {
                res[i % n] = preSum[i] - preSum[i + k];
            }
        }
        return res;
    }
};