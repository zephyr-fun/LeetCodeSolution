// 2022.04.19
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> degree(n + 1, vector<int>(2, 0)); // 1-n
        for(int i = 0; i < trust.size(); i++) {
            degree[trust[i][0]][1]++;
            degree[trust[i][1]][0]++;
        }
        for(int i = 1; i <= n; i++) {
            if(degree[i][0] == n - 1 && degree[i][1] == 0) {
                return i;
            }
        }
        return -1;
    }
};