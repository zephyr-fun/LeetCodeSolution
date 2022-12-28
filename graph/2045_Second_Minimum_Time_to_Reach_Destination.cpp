// 2022.12.28
// https://leetcode.cn/problems/second-minimum-time-to-reach-destination/solution/gong-shui-san-xie-yi-ti-shuang-jie-dui-y-88np/
// https://mp.weixin.qq.com/s?__biz=MzU4NDE3MTEyMA==&mid=2247488007&idx=1&sn=9d0dcfdf475168d26a5a4bd6fcd3505d
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> grid(n + 1);
        vector<int> dist1(n + 1, INF);
        vector<int> dist2(n + 1, INF);
        for(auto& edge: edges) {
            grid[edge[0]].push_back(edge[1]);
            grid[edge[1]].push_back(edge[0]);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pque;
        pque.emplace(0, 1);
        dist1[1] = 0;
        while(!pque.empty()) {
            auto [distance, u] = pque.top();
            pque.pop();
            if(distance != dist1[u] && distance != dist2[u]) {
                continue;
            }
            for(int v : grid[u]) {
                int a = distance / change;
                int b = distance % change;
                int wait = a % 2 == 0 ? 0 : change - b;
                int w = distance + time + wait;
                if (dist1[v] > w) {
                    dist2[v] = dist1[v];
                    dist1[v] = w;
                    pque.emplace(dist1[v], v);
                }
                else if (dist1[v] < w && w < dist2[v]) {
                    dist2[v] = w;
                    pque.emplace(dist2[v], v);
                }
            }
        }
        return dist2[n];
    }
};