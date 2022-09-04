// 2022.09.04
class Solution {
public:
    vector<vector<int>> mat;
    vector<int> mat_bit;
    int cols;
    int n;
    int m;
    vector<int> path;
    vector<vector<int>> temp;
    vector<int> bit;
    int check(int& t) {
        int res = 0;
        // cout << t << endl;
        for(auto& mb : mat_bit) {
            cout << mb << endl;
            bool flag = true;
            for(int i = 0; i < m; i++) {
                cout << ((t >> i) & 1) << ((mb >> i) & 1) << "|";
                if(((t >> i) & 1) < ((mb >> i) & 1)) {
                    flag = false;
                    break;
                }
            }
            cout << endl;
            res += flag ? 1 : 0;
        }
        return res;
    }
    void dfs(int start, int cnt) {
        // cout << start << cnt << endl;
        if(cnt == cols) {
            // cout << ">" << endl;
            temp.emplace_back(path);
            return ;
        }
        for(int i = start; i < m; i++) {
            path.emplace_back(i);
            dfs(i + 1, cnt + 1);
            path.pop_back();
        }
    }
    int maximumRows(vector<vector<int>>& mat_, int cols_) {
        mat = mat_;
        cols = cols_;
        n = mat.size();
        m = mat[0].size();
        dfs(0, 0);
        for(auto& t : temp) {
            int a = 0;
            for(auto& num : t) {
                a |= 1 << num;
            }
            bit.emplace_back(a);
        }
        for(int i = 0; i < n; i++) {
            int a = 0;
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 1) {
                    a |= 1 << (m - 1 - j);
                }
            }
            // cout << a << "a" << endl;
            mat_bit.emplace_back(a);
        }
        int res = 0;
        for(auto& b : bit) {
            res = max(res, check(b));
            // cout << b << check(b) << endl;
        }
        return res;
    }
};