// 2022.06.07
// binary search + bfs
class Solution {
public:
    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> grid_;
    int n_;
    int swimInWater(vector<vector<int>>& grid) {
        grid_ = grid;
        int maxHeight = 0;
        int n = grid.size();
        n_ = n;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                maxHeight = max(maxHeight, grid[i][j]);
            }
        }
        int left = 0;
        int right = maxHeight;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(flood(mid)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
    bool flood(int depth) {
        vector<vector<bool>> visit(n_, vector<bool>(n_, false));
        queue<pair<int, int>> que;
        if(depth < grid_[0][0]) {
            return false;
        }
        que.emplace(0, 0);
        visit[0][0] = true;
        while(!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for(int k = 0; k < 4; k++) {
                int nextI = i + dirs[k][0];
                int nextJ = j + dirs[k][1];
                if(nextI < 0 || nextI >= n_ || nextJ < 0 || nextJ >= n_) {
                    continue;
                }
                if(grid_[nextI][nextJ] > depth || visit[nextI][nextJ] == true) {
                    continue;
                }
                visit[nextI][nextJ] = true;
                que.emplace(nextI, nextJ);
            }
        }
        return visit[n_ - 1][n_ - 1];
    }
};

// UnionFindSet
class UnionFindSet {
public:
    UnionFindSet(int n): rank_(n + 1, 0), parent_(n + 1, 0) {
        for(int i = 0; i < parent_.size(); i++) {
            parent_[i] = i;
        }
    }

    int Find(int u) {
        if(u != parent_[u]) {
            parent_[u] = Find(parent_[u]);
        }
        return parent_[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(rank_[pu] < rank_[pv]) {
            parent_[pu] = pv;
        }
        else if(rank_[pu] > rank_[pv]) {
            parent_[pv] = pu;
        }
        else {
            parent_[pv] = pu;
            rank_[pu]++;
        }
        return true;
    }

private:
    vector<int> rank_;
    vector<int> parent_;
};
class Solution {
public:
    int n;
    int getIdx(int i, int j) {
        return i * n + j;
    }
    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();
        UnionFindSet set(n * n);
        vector<vector<int>> edge;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(j + 1 < n) {
                    vector<int> temp;
                    temp.emplace_back(getIdx(i, j));
                    temp.emplace_back(getIdx(i, j + 1));
                    temp.emplace_back(max(grid[i][j], grid[i][j + 1]));
                    edge.emplace_back(temp);
                }
                if(i + 1 < n) {
                    vector<int> temp;
                    temp.emplace_back(getIdx(i, j));
                    temp.emplace_back(getIdx(i + 1, j));
                    temp.emplace_back(max(grid[i][j], grid[i + 1][j]));
                    edge.emplace_back(temp);
                }
            }
        }
        sort(edge.begin(), edge.end(), [](vector<int>& a, vector<int>& b) {
            return a[2] < b[2];
        });
        int start = getIdx(0, 0);
        int end = getIdx(n - 1, n - 1);
        for(auto ed : edge) {
            int a = ed[0];
            int b = ed[1];
            int w = ed[2];
            set.Union(a, b);
            if(set.Find(start) == set.Find(end)) {
                return w;
            }
        }
        return 0;
    }
};

// 2022.06.21
// unionfindset
class UnionFindSet {
public:
    UnionFindSet(int n): rank(n + 1, 0), parent(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if(u != parent[u]) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
private:
    vector<int> rank;
    vector<int> parent;
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0;
        int right = n * n - 1;
        int res = -1;
        while(left <= right) {
            UnionFindSet set(n * n);
            int mid = left + (right - left) / 2;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] <= mid) {
                        if(i + 1 < n && grid[i + 1][j] <= mid) {
                            set.Union(i * n + j, (i + 1) * n + j);
                        }
                        if(j + 1 < n && grid[i][j + 1] <= mid) {
                            set.Union(i * n + j, i * n + (j + 1));
                        }
                    }
                }
            }
            if(set.Find(0) == set.Find(n * n - 1)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};

// 2022.07.29
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1), rank(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if(u != parent[u]) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
};
class Solution {
public:
    int getIdx(int i, int j, int n) {
        return i * n + j;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0;
        int right = n * n - 1;
        int res = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            UnionFindSet set(n * n);
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] <= mid) {
                        if(i + 1 < n && grid[i + 1][j] <= mid) {
                            set.Union(getIdx(i, j, n), getIdx(i + 1, j, n));
                        }
                        if(j + 1 < n && grid[i][j + 1] <= mid) {
                            set.Union(getIdx(i, j, n), getIdx(i, j + 1, n));
                        }
                    }
                }
            }
            if(set.Find(0) == set.Find(n * n - 1)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};