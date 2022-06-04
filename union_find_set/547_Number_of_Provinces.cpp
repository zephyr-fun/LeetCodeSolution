// 2022.06.04
// union_find_set
class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);
        parent_ = vector<int>(n + 1, 0);
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
        if(pu < pv) {
            parent_[pu] = pv;
        }
        else if(pu > pv) {
            parent_[pv] = pu;
        }
        else {
            parent_[pu] = pv;
            ranks_[pu] += 1;
        }
        return true;
    }
private:
    vector<int> ranks_;
    vector<int> parent_;
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFindSet set(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    set.Union(i, j);
                }
            }
        }
        unordered_set<int> res;
        for(int i = 0; i < n; i++) {
            res.insert(set.Find(i));
        }
        return res.size();
    }
};

// dfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(isConnected, visited, n, i);
                res++;
            }
        }
        return res;
    }
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int n, int i) {
        for(int j = 0; j < n; j++) {
            if(isConnected[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(isConnected, visited, n, j);
            }
        }
    }
};

// bfs
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        queue<int> que;
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                que.push(i);
                while(!que.empty()) {
                    int city = que.front();
                    que.pop();
                    for(int j = 0; j < n; j++) {
                        if(isConnected[city][j] == 1 && !visited[j]) {
                            visited[j] = true;
                            que.push(j);
                        }
                    } 
                }
                res++;
            }
        }
        return res;
    }
};