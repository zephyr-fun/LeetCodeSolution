// 2023.06.10
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int res = 0;
        int n = reward1.size();
        for(int i = 0; i < n; i++) {
            res += reward2[i];
            reward1[i] = reward1[i] - reward2[i];
        }
        sort(reward1.begin(), reward1.end(), [] (int& a, int& b) {
            return a > b;
        });
        return res + accumulate(reward1.begin(), reward1.begin() + k, 0);
    }
};