// 2022.10.11
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> in(n, 0);
        vector<vector<int>> grid(n, vector<int>());
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
            res.emplace_back(cur);
            for(auto& next : grid[cur]) {
                in[next]--;
                if(in[next] == 0) {
                    que.push(next);
                }
            }
        }
        return res.size() == n ? res : vector<int>();
    }
};

// 2022.12.06
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> in(numCourses, 0);
        int n = prerequisites.size();
        vector<vector<int>> g(numCourses);
        for(auto& pre : prerequisites) {
            in[pre[0]]++;
            g[pre[1]].emplace_back(pre[0]);
        }
        stack<int> st;
        for(int i = 0; i < numCourses; i++) {
            if(in[i] == 0) {
                st.push(i);
            }
        }
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            res.emplace_back(u);
            for(auto& v : g[u]) {
                in[v]--;
                if(in[v] == 0) {
                    st.push(v);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};

// 2023.09.13
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses, 0);
        for (auto& pre : prerequisites) {
            g[pre[1]].emplace_back(pre[0]);
            in[pre[0]]++;
        }
        vector<int> result;
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            result.emplace_back(u);
            for (auto& v : g[u]) {
                in[v]--;
                if (in[v] == 0) {
                    que.push(v);
                }
            }
        }
        if (result.size() == numCourses) {
            return result;
        }
        return vector<int>();
    }
};

// 2023.09.21
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> in(numCourses, 0);
        vector<int> res;
        for (auto& pre : prerequisites) {
            g[pre[1]].emplace_back(pre[0]);
            in[pre[0]]++;
        }
        queue<int> que;
        for (int i = 0; i < numCourses; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            res.emplace_back(u);
            for (auto& v : g[u]) {
                if (--in[v] == 0) {
                    que.push(v);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>();
    }
};