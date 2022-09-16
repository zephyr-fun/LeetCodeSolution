// 2022.09.16
// merge segment
typedef long long LL;
typedef pair<int, int> PII;
// #define x first
// #define y second

class Solution {
public:
    LL calc(vector<vector<int>>& rts, int a, int b) {
        vector<PII> row;
        for(auto& rt : rts) {
            if(rt[0] <= a && rt[2] >= b) {
                row.emplace_back(make_pair(rt[1], rt[3]));
            }
        }
        sort(row.begin(), row.end());
        LL res = 0;
        LL st = -1;
        LL ed = -1;
        for(auto& r : row) {
            if(r.first > ed) {
                res += ed - st;
                st = r.first;
                ed = r.second;
            }
            else {
                if(r.second > ed) {
                    ed = r.second;
                }
            }
        }
        res += ed - st;
        return res * (b - a);
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1e9 + 7;
        vector<int> col;
        for(auto& rt : rectangles) {
            col.emplace_back(rt[0]);
            col.emplace_back(rt[2]);
        }
        sort(col.begin(), col.end());
        LL res = 0;
        for(int i = 1; i < col.size(); i++) {
            res += calc(rectangles, col[i - 1], col[i]);
        }
        return res % mod;
    }
};