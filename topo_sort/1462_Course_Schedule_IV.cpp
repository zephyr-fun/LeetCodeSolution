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