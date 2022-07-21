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