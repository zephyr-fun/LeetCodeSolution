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