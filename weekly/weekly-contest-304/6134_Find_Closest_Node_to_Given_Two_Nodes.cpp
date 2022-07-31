// 2022.07.31
class Solution {
public:
    int n;
    vector<vector<int>> g;
    void bfs(unordered_map<int, int>& map, int node) {
        map[node] = 0;
        queue<int> que;
        que.push(node);
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            int step = map[cur];
            for(auto next : g[cur]) {
                if(next == -1) {
                    continue;
                }
                if(map.count(next)) {
                    continue;
                }
                map[next] = step + 1;
                que.push(next);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, int> map1;
        unordered_map<int, int> map2;
        n = edges.size();
        g.resize(n);
        for(int i = 0; i < n; i++) {
            g[i].emplace_back(edges[i]);
        }
        bfs(map1, node1);
        bfs(map2, node2);
        int res = 0x3f3f3f3f;
        int idx = -1;
        for(int i = 0; i < n; i++) {
            if(map1.count(i) && map2.count(i)) {
                if(res > max(map1[i], map2[i])) {
                    res = max(map1[i], map2[i]);
                    idx = i;
                }
            }
        }
        return idx;
    }
};