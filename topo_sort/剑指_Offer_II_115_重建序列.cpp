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

// 2022.08.26
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> path;
        vector<int> d(n + 1, 0);
        vector<vector<int>> grid(n + 1);
        for(auto& seq : sequences) {
            for(int i = 0; i < seq.size() - 1; i++) {
                grid[seq[i]].emplace_back(seq[i + 1]);
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
            int size = que.size();
            if(size > 1) {
                return false;
            }
            int cur = que.front();
            que.pop();
            path.emplace_back(cur);
            for(auto& v : grid[cur]) {
                d[v]--;
                if(d[v] == 0) {
                    que.push(v);
                }
            }
        }
        if(nums.size() != path.size()) {
            return false;
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != path[i]) {
                return false;
            }
        }
        return true;
    }
};

// 2023.09.22
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {
        int n = nums.size();
        vector<int> path;
        vector<vector<int>> g(n + 1);
        vector<int> in(n + 1, 0);
        for (auto& s : sequences) {
            for (int i = 0; i < s.size() - 1; i++) {
                g[s[i]].emplace_back(s[i + 1]);
                in[s[i + 1]]++;
            }
        }
        queue<int> que;
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0) {
                que.push(i);
            }
        }
        while (!que.empty()) {
            int size = que.size();
            if (size > 1) {
                return false;
            }
            int u = que.front();
            que.pop();
            path.emplace_back(u);
            for (auto& v : g[u]) {
                if (--in[v] == 0) {
                    que.push(v);
                }
            }
        }
        if (nums.size() != path.size()) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != path[i]) {
                return false;
            }
        }
        return true;
    }
};