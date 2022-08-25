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