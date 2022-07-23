// 2022.07.23
// whether the graph has a unique topo order
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<vector<int>> g(n + 1);
        vector<int> d(n + 1);
        for(auto seq : sequences) {
            for(int i = 0; i < seq.size() - 1; i++) {
                g[seq[i]].emplace_back(seq[i + 1]);
                d[seq[i + 1]]++;
            }
            
        }
        queue<int> que;
        for(int i = 1; i <= n; i++) {
            if(d[i] == 0) {
                que.push(i);
            }
        }
        while(!que.empty()) {
            if(que.size() > 1) {
                return false;
            }
            int u = que.front();
            que.pop();
            for(auto v : g[u]) {
                d[v]--;
                if(d[v] == 0) {
                    que.push(v);
                }
            }
        }
        return true;
    }
};