// 2022.10.11
// flyod K
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isReachable(n, vector<bool>(n, false));
        for(auto& pre : prerequisites) {
            isReachable[pre[1]][pre[0]] = true;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(isReachable[i][k] && isReachable[k][j]) {
                        isReachable[i][j] = true;
                    }
                }
            }
        }
        vector<bool> res(queries.size(), false);
        for(int i = 0; i < queries.size(); i++) {
            res[i] = isReachable[queries[i][1]][queries[i][0]];
        }
        return res;
    }
};

// topo
class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<unordered_set<int>> set(n);
        vector<vector<int>> grid(n, vector<int>());
        vector<int> in(n, 0);
        for(auto& pre : prerequisites) {
            grid[pre[1]].emplace_back(pre[0]);
            in[pre[0]]++;
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
                // add
                set[next].insert(set[cur].begin(), set[cur].end());
                set[next].insert(cur);
                if(in[next] == 0) {
                    que.push(next);
                }
            }
        }
        vector<bool> res;
        for(auto& q : queries) {
            if(set[q[0]].count(q[1])) {
                res.emplace_back(true);
            }
            else {
                res.emplace_back(false);
            }
        }
        return res;
    }
};

// 2023.09.13
// 先修课的语义顺序和1，2是反的，不过不影响，只有 this line 标记行需要反顺序反语义
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> result(n, false);
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses, 0);
        vector<unordered_set<int>> preset(numCourses);
        for (auto& pre : prerequisites) {
            g[pre[1]].emplace_back(pre[0]);
            in[pre[0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                que.emplace(i);
            }
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (auto& v : g[u]) {
                for (auto& inderct : preset[u]) {
                    preset[v].insert(inderct);
                }
                preset[v].insert(u);
                in[v]--;
                if (in[v] == 0) {
                    que.emplace(v);
                }
            }
        }
        int idx = 0;
        for (auto& query : queries) {
            result[idx++] = preset[query[0]].count(query[1]); // this line
        }
        return result;
    }
};

// floyd
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> isReachable(numCourses, vector<bool>(numCourses, false));
        for (auto& pre : prerequisites) {
            isReachable[pre[1]][pre[0]] = true;
        }
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (isReachable[i][k] && isReachable[k][j]) {
                        isReachable[i][j] = true;
                    }
                }
            }
        }

        vector<bool> result;
        for (auto& query : queries) {
            result.emplace_back(isReachable[query[1]][query[0]]);
        }
        return result;
    }
};