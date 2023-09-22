// 2023.01.25
// union find set + topo sort
typedef pair<int, int> pii;
class UnionFindSet {
public:
    UnionFindSet(int n_, int m_) {
        n = n_;
        m = m_;
        parent = vector<vector<pii>>(n, vector<pii>(m));
        size = vector<vector<int>>(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                parent[i][j] = make_pair(i, j);
                size[i][j] = 1;
            }
        }
    }

    pii Find(int i, int j) {
        if(parent[i][j].first != i || parent[i][j].second != j) {
            auto temp = Find(parent[i][j].first, parent[i][j].second);
            parent[i][j].first = temp.first;
            parent[i][j].second = temp.second;
        }
        return parent[i][j];
    }

    bool Union(int i1, int j1, int i2, int j2) {
        auto [pi1, pj1] = Find(i1, j1);
        auto [pi2, pj2] = Find(i2, j2);
        if(pi1 == pi2 && pj1 == pj2) {
            return false;
        }
        if(size[pi1][pj1] >= size[pi2][pj2]) {
            parent[pi2][pj2] = make_pair(pi1, pj1);
            size[pi1][pj1] += size[pi2][pj2];
        }
        else {
            parent[pi1][pj1] = make_pair(pi2, pj2);
            size[pi2][pj2] += size[pi1][pj1];
        }
        return true;
    }
private:
    int n;
    int m;
    vector<vector<pii>> parent;
    vector<vector<int>> size;
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        UnionFindSet set(n, m);
        for(int i = 0; i < n; i++) {
            unordered_map<int, vector<pii>> map;
            for(int j = 0; j < m; j++) {
                map[matrix[i][j]].emplace_back(make_pair(i, j));
            }
            for(auto [_, numIdx] : map) {
                int i1 = numIdx[0].first;
                int j1 = numIdx[0].second;
                for(int k = 1; k < numIdx.size(); k++) {
                    int i2 = numIdx[k].first;
                    int j2 = numIdx[k].second;
                    set.Union(i1, j1, i2, j2);
                }
            }
        }
        for(int j = 0; j < m; j++) {
            unordered_map<int, vector<pii>> map;
            for(int i = 0; i < n; i++) {
                map[matrix[i][j]].emplace_back(make_pair(i, j));
            }
            for(auto [_, numIdx] : map) {
                int i1 = numIdx[0].first;
                int j1 = numIdx[0].second;
                for(int k = 1; k < numIdx.size(); k++) {
                    int i2 = numIdx[k].first;
                    int j2 = numIdx[k].second;
                    set.Union(i1, j1, i2, j2);
                }
            }
        }
        vector<vector<int>> in(n, vector<int>(m));
        unordered_map<int, vector<pii>> adj;
        for(int i = 0; i < n; i++) {
            unordered_map<int, pii> map;
            for(int j = 0; j < m; j++) {
                map[matrix[i][j]] = make_pair(i, j);
            }
            vector<int> sorted;
            for(auto [key, _] : map) {
                sorted.emplace_back(key);
            }
            sort(sorted.begin(), sorted.end());
            for(int k = 1; k < sorted.size(); k++) {
                auto [i1, j1] = map[sorted[k - 1]];
                auto [i2, j2] = map[sorted[k]];
                auto [pi1, pj1] = set.Find(i1, j1);
                auto [pi2, pj2] = set.Find(i2, j2);
                in[pi2][pj2]++;
                adj[pi1 * m + pj1].emplace_back(pi2, pj2);
            }
        }
        for(int j = 0; j < m; j++) {
            unordered_map<int, pii> map;
            for(int i = 0; i < n; i++) {
                map[matrix[i][j]] = make_pair(i, j);
            }
            vector<int> sorted;
            for(auto [key, _] : map) {
                sorted.emplace_back(key);
            }
            sort(sorted.begin(), sorted.end());
            for(int k = 1; k < sorted.size(); k++) {
                auto [i1, j1] = map[sorted[k - 1]];
                auto [i2, j2] = map[sorted[k]];
                auto [pi1, pj1] = set.Find(i1, j1);
                auto [pi2, pj2] = set.Find(i2, j2);
                in[pi2][pj2]++;
                adj[pi1 * m + pj1].emplace_back(pi2, pj2);
            }
        }
        vector<vector<int>> rank(n, vector<int>(m));
        unordered_set<int> rootSet;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                auto [pi, pj] = set.Find(i, j);
                rootSet.insert(pi * m + pj);
                rank[pi][pj] = 1;
            }
        }
        queue<pii> que;
        for(int val : rootSet) {
            if(in[val / m][val % m] == 0) {
                que.emplace(val / m, val % m);
            }
        }
        while(!que.empty()) {
            auto[i, j] = que.front();
            que.pop();
            for(auto[ui, uj] : adj[i * m + j]) {
                in[ui][uj]--;
                if(in[ui][uj] == 0) {
                    que.emplace(ui, uj);
                }
                rank[ui][uj] = max(rank[ui][uj], rank[i][j] + 1);
            }
        }
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                auto[pi, pj] = set.Find(i, j);
                res[i][j] = rank[pi][pj];
            }
        }
        return res;
    }
};

// 2023.09.21
// 2023.01.25
// union find set + topo sort
typedef pair<int, int> pii;
class UnionFindSet {
public:
    UnionFindSet(int n_, int m_) {
        n = n_;
        m = m_;
        parent = vector<vector<pii>>(n, vector<pii>(m));
        size = vector<vector<int>>(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                parent[i][j] = make_pair(i, j);
                size[i][j] = 1;
            }
        }
    }

    pii Find(int i, int j) {
        if(parent[i][j].first != i || parent[i][j].second != j) {
            auto temp = Find(parent[i][j].first, parent[i][j].second);
            parent[i][j].first = temp.first;
            parent[i][j].second = temp.second;
        }
        return parent[i][j];
    }

    bool Union(int i1, int j1, int i2, int j2) {
        auto [pi1, pj1] = Find(i1, j1);
        auto [pi2, pj2] = Find(i2, j2);
        if(pi1 == pi2 && pj1 == pj2) {
            return false;
        }
        if(size[pi1][pj1] >= size[pi2][pj2]) {
            parent[pi2][pj2] = make_pair(pi1, pj1);
            size[pi1][pj1] += size[pi2][pj2];
        }
        else {
            parent[pi1][pj1] = make_pair(pi2, pj2);
            size[pi2][pj2] += size[pi1][pj1];
        }
        return true;
    }
private:
    int n;
    int m;
    vector<vector<pii>> parent;
    vector<vector<int>> size;
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        UnionFindSet set(n, m);
        for(int i = 0; i < n; i++) {
            unordered_map<int, vector<pii>> map;
            for(int j = 0; j < m; j++) {
                map[matrix[i][j]].emplace_back(make_pair(i, j));
            }
            for(auto [_, numIdx] : map) {
                int i1 = numIdx[0].first;
                int j1 = numIdx[0].second;
                for(int k = 1; k < numIdx.size(); k++) {
                    int i2 = numIdx[k].first;
                    int j2 = numIdx[k].second;
                    set.Union(i1, j1, i2, j2);
                }
            }
        }
        for(int j = 0; j < m; j++) {
            unordered_map<int, vector<pii>> map;
            for(int i = 0; i < n; i++) {
                map[matrix[i][j]].emplace_back(make_pair(i, j));
            }
            for(auto [_, numIdx] : map) {
                int i1 = numIdx[0].first;
                int j1 = numIdx[0].second;
                for(int k = 1; k < numIdx.size(); k++) {
                    int i2 = numIdx[k].first;
                    int j2 = numIdx[k].second;
                    set.Union(i1, j1, i2, j2);
                }
            }
        }
        vector<vector<int>> in(n, vector<int>(m));
        unordered_map<int, vector<pii>> adj;
        for(int i = 0; i < n; i++) {
            unordered_map<int, pii> map;
            for(int j = 0; j < m; j++) {
                map[matrix[i][j]] = make_pair(i, j);
            }
            vector<int> sorted;
            for(auto [key, _] : map) {
                sorted.emplace_back(key);
            }
            sort(sorted.begin(), sorted.end());
            for(int k = 1; k < sorted.size(); k++) {
                auto [i1, j1] = map[sorted[k - 1]];
                auto [i2, j2] = map[sorted[k]];
                auto [pi1, pj1] = set.Find(i1, j1);
                auto [pi2, pj2] = set.Find(i2, j2);
                in[pi2][pj2]++;
                adj[pi1 * m + pj1].emplace_back(pi2, pj2);
            }
        }
        for(int j = 0; j < m; j++) {
            unordered_map<int, pii> map;
            for(int i = 0; i < n; i++) {
                map[matrix[i][j]] = make_pair(i, j);
            }
            vector<int> sorted;
            for(auto [key, _] : map) {
                sorted.emplace_back(key);
            }
            sort(sorted.begin(), sorted.end());
            for(int k = 1; k < sorted.size(); k++) {
                auto [i1, j1] = map[sorted[k - 1]];
                auto [i2, j2] = map[sorted[k]];
                auto [pi1, pj1] = set.Find(i1, j1);
                auto [pi2, pj2] = set.Find(i2, j2);
                in[pi2][pj2]++;
                adj[pi1 * m + pj1].emplace_back(pi2, pj2);
            }
        }
        vector<vector<int>> rank(n, vector<int>(m));
        unordered_set<int> rootSet;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                auto [pi, pj] = set.Find(i, j);
                rootSet.insert(pi * m + pj);
            }
        }
        queue<pii> que;
        for(int val : rootSet) {
            if(in[val / m][val % m] == 0) {
                que.emplace(val / m, val % m);
                rank[val / m][val % m] = 1;
            }
        }
        while(!que.empty()) {
            auto[i, j] = que.front();
            que.pop();
            for(auto[ui, uj] : adj[i * m + j]) {
                in[ui][uj]--;
                if(in[ui][uj] == 0) {
                    que.emplace(ui, uj);
                }
                rank[ui][uj] = max(rank[ui][uj], rank[i][j] + 1);
            }
        }
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                auto[pi, pj] = set.Find(i, j);
                res[i][j] = rank[pi][pj];
            }
        }
        return res;
    }
};