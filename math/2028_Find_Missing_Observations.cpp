// 2022.12.10
class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = (rolls.size() + n) * mean;
        int target = sum - accumulate(rolls.begin(), rolls.end(), 0);
        if(target > n * 6 || target < n) {
            return {};
        }
        int nmean = target / n;
        int residual = target - n * nmean;
        vector<int> res(n, nmean);
        int idx = 0;
        while(residual) {
            res[idx]++;
            idx++; // non need to take mod
            residual--;
        }
        return res;
    }
};