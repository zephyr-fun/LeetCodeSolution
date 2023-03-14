// 2023.03.14
// 其实是运筹学内容，表上作业法找初始可行解的过程。有西北角法、最小元素法、伏格尔法等方法。
// 等价于n^2个变量，2n个约束条件，目标函数为一个常数的优化问题
// O(n*m)
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res[i][j] = min(rowSum[i], colSum[j]);
                rowSum[i] -= res[i][j];
                colSum[j] -= res[i][j];
            }
        }
        return res;
    }
};

// optim
// upper bound O(n + m - 1)
// 每次选择确定一行或一列
class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> res(n, vector<int>(m, 0));
        for(int i = 0, j = 0; i < n && j < m; ) {
            int rs = rowSum[i];
            int cs = colSum[j];
            // 如果行和小于列和，贪心选择行和作为当前返回值，当前值右边全置为0，直接计算下一行（向下）
            if(rs < cs) {
                res[i][j] = rs;
                colSum[j] -= rs;
                i++;
            }
            // 如果行和大于列和，贪心选择列和作为当前返回值，当前值下边全置为0，直接计算下一列（向右）
            else {
                res[i][j] = cs;
                rowSum[i] -= cs;
                j++;
            }
        }
        return res;
    }
};