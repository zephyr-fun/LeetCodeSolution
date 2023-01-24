// 2023.01.24
class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            for(auto& point : points) {
                if(pow(abs(x - point[0]), 2) + pow(abs(y - point[1]), 2) <= r * r) {
                    res[i]++;
                }
            }
        }
        return res;
    }
};