// 2022.07.21
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> d(numCourses);
        for(auto pre : prerequisites) {
            g[pre[1]].emplace_back(pre[0]);
            d[pre[0]]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++) {
            if(d[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(int i = 0; i < g[cur].size(); i++) {
                d[g[cur][i]]--;
                if(d[g[cur][i]] == 0) {
                    que.push(g[cur][i]);
                }
            }
        }
        for(int i = 0; i < numCourses; i++) {
            if(d[i]) {
                return false;
            }
        }
        return true;
    }
};

// 2022.10.11
class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> in(n, 0);
        vector<vector<int>> grid(n, vector<int>());
        for(auto& pre : prerequisites) {
            in[pre[1]]++;
            grid[pre[0]].emplace_back(pre[1]);
        }
        queue<int> que;
        for(int i = 0; i < n; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(auto& next : grid[cur]) {
                in[next]--;
                if(in[next] == 0) {
                    que.push(next);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(in[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

// 2023.01.29
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> in(numCourses, 0);
        for(auto& pre : prerequisites) {
            adj[pre[1]].emplace_back(pre[0]);
            in[pre[0]]++;
        }
        queue<int> que;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            for(auto& v : adj[u]) {
                in[v]--;
                if(in[v] == 0) {
                    que.push(v);
                }
            }
        }
        for(int i = 0; i < numCourses; i++) {
            if(in[i]) {
                return false;
            }
        }
        return true;
    }
};