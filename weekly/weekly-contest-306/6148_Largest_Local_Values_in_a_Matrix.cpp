// 2022.08.14 contest 2022.08.15 update
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                for(int x = i; x <= i + 2; x++) {
                    for(int y = j; y <= j + 2; y++) {
                        res[i][j] = max(res[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};

// 2023.03.01
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0));
        // i, j -> (n - 2, n - 2)
        for(int i = 0; i < n - 2; i++) {
            for(int j = 0; j < n - 2; j++) {
                // x, y -> (n, n)
                for(int x = i; x <= i + 2; x++) { 
                    for(int y = j; y <= j + 2; y++) {
                        res[i][j] = max(res[i][j], grid[x][y]);
                    }
                }
            }
        }
        return res;
    }
};

// monotonic queue
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>> grid) {
        int n = grid.size();
        vector<vector<int>> res(n - 2, vector<int>(n - 2, 0)); // 创建结果数组
        deque<int> queue;  // 单调队列
        int value;
        for (int i = 0; i < n; i++) {
            queue.clear(); // 每一行新建一个单调队列
            for (int j = 0; j < n; j++) {
                // 单调队列添加候选值
                while (!queue.empty() && grid[i][j] >= grid[i][queue.back()]) {
                    queue.pop_back();
                }
                queue.push_back(j);
                // 滑动窗口达到大小3可以处理
                if (j >= 2) {
                    value = grid[i][queue.front()]; // 获取单调队列中当前行当前滑动窗口中的最大值，即队首索引对应的值
                    for (int k = i - 2; k <= i; k++) { // 更新当前行及其前两行该列的最大值
                        if (k >= 0 && k < n - 2) { // 行必须在结果数组的范围内
                            res[k][j - 2] = max(res[k][j - 2], value);
                        }
                    }
                    if (queue.front() <= j - 2) { // 当前最大值位于滑动窗口最左侧，弹出这个最大值
                        queue.pop_front();
                    }
                }
            }
        }
        return res;
    }
};