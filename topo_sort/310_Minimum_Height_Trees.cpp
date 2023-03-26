// 2022.08.25
// topo
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) {
            return {0};
        }
        vector<vector<int>> grid(n);
        vector<int> d(n, 0);
        for(auto edge : edges) {
            grid[edge[0]].emplace_back(edge[1]);
            grid[edge[1]].emplace_back(edge[0]);
            d[edge[0]]++;
            d[edge[1]]++;
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(d[i] == 1) {
                que.push(i);
            }
        }
        int cnt = n;
        while(cnt > 2) {
            int size = que.size();
            cnt -= size;
            for(int i = 0; i < size; i++) {
                int cur = que.front();
                que.pop();
                for(auto v : grid[cur]) {
                    d[v]--;
                    if(d[v] == 1) {
                        que.push(v);
                    }
                }
            }
        }
        vector<int> res;
        while(!que.empty()) {
            res.emplace_back(que.front());
            que.pop();
        }
        return res;
    }
};

// bfs
class Solution {
public:
    int n;
    vector<vector<int>> grid;
    void traversal(int cur, vector<int>& parent, vector<int>& dist) {
        for(auto& v : grid[cur]) {
            if(dist[v] < 0) {
                dist[v] = dist[cur] + 1;
                parent[v] = cur;
                traversal(v, parent, dist);
            }
        }
    }
    int findNode(int cur, vector<int>& parent) {
        vector<int> dist(n, -1);
        dist[cur] = 0;
        parent[cur] = -1;
        queue<int> que;
        que.push(cur);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(auto& v : grid[u]) {
                if(dist[v] < 0) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    que.push(v);
                }
            }
        }
        int maxDepth = -1;
        int res = -1;
        for(int i = 0; i < n; i++) {
            // cout << "i:" << i << "p:" << parent[i] << "d:" << dist[i] << endl;
            if(dist[i] > maxDepth) {
                maxDepth = dist[i];
                res = i;
            }
        }
        return res;
    }
    vector<int> findMinHeightTrees(int n_, vector<vector<int>>& edges) {
        n = n_;
        if(n == 1) {
            return {0};
        }
        grid.resize(n);
        for(auto edge : edges) {
            grid[edge[0]].emplace_back(edge[1]);
            grid[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        int x = findNode(0, parent);
        int y = findNode(x, parent);
        vector<int> path;
        while(y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int size = path.size();
        if(size & 1) {
            return {path[(size - 1) / 2]};
        }
        return {path[(size - 1) / 2], path[size / 2]};
    }
};

// dfs
class Solution {
public:
    int n;
    vector<vector<int>> grid;
    void traversal(int cur, vector<int>& parent, vector<int>& dist) {
        for(auto& v : grid[cur]) {
            if(dist[v] < 0) {
                dist[v] = dist[cur] + 1;
                parent[v] = cur;
                traversal(v, parent, dist);
            }
        }
    }
    int findNode(int cur, vector<int>& parent) {
        vector<int> dist(n, -1);
        dist[cur] = 0;
        parent[cur] = -1;
        traversal(cur, parent, dist);
        int maxDepth = -1;
        int res = -1;
        for(int i = 0; i < n; i++) {
            // cout << "i:" << i << "p:" << parent[i] << "d:" << dist[i] << endl;
            if(dist[i] > maxDepth) {
                maxDepth = dist[i];
                res = i;
            }
        }
        return res;
    }
    vector<int> findMinHeightTrees(int n_, vector<vector<int>>& edges) {
        n = n_;
        if(n == 1) {
            return {0};
        }
        grid.resize(n);
        for(auto edge : edges) {
            grid[edge[0]].emplace_back(edge[1]);
            grid[edge[1]].emplace_back(edge[0]);
        }
        vector<int> parent(n, -1);
        int x = findNode(0, parent);
        int y = findNode(x, parent);
        vector<int> path;
        while(y != -1) {
            path.emplace_back(y);
            y = parent[y];
        }
        int size = path.size();
        if(size & 1) {
            return {path[(size - 1) / 2]};
        }
        return {path[(size - 1) / 2], path[size / 2]};
    }
};

// 2023.03.26
// 树形DP -> 换根DP
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for(auto& e : edges) {
            int a = e[0];
            int b = e[1];
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
        vector<int> d1, d2, p1, p2, up;
        d1 = d2 = p1 = p2 = up = vector<int>(n, 0);
        // 用于求d1，d2的值，以u为求解当前点
        // d1[u]代表u节点向下最长路径值，p1[u]代表最长路径值是从哪个子节点走的
        // d2[u]代表u节点向下非严格次长路径值，p2[u]代表非严格次长路径值是从哪个子节点走的
        function<void(int, int)> dfs1 = [&] (int u, int father) {
            for(int x : g[u]) {
                if(x == father) {
                    continue;
                }
                dfs1(x, u);
                int d = d1[x] + 1;
                if(d >= d1[u]) {
                    d2[u] = d1[u];
                    d1[u] = d;
                    p2[u] = p1[u];
                    p1[u] = x;
                }
                else if(d > d2[u]) {
                    d2[u] = d;
                    p2[u] = x;
                }
            }
        };
        // 用于求up[x]的值，以x为求解当前点
        // 如果p1[u]是x的话，从u出发的向下的路径就不能选x所代表的最长路径了（折返路径不合法）
        // 如果p1[u]不是x的话，从u出发的向下的路径就可以选u的另一个子节点所代表的最长路径了
        function<void(int, int)> dfs2 = [&] (int u, int father) {
            for(int x : g[u]) {
                if(x == father) {
                    continue;
                }
                if(p1[u] == x) {
                    up[x] = max(up[u], d2[u]) + 1;
                }
                else {
                    up[x] = max(up[u], d1[u]) + 1;
                }
                dfs2(x, u);
            }
        };
        dfs1(0, -1);
        dfs2(0, -1);
        int mind = n + 1;
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int cur = max(d1[i], up[i]);
            if(cur < mind) {
                mind = cur;
                res.clear();
                res.emplace_back(i);
            }
            else if(cur == mind) {
                res.emplace_back(i);
            } 
        }
        return res;
    }
};