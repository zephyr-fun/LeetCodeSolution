// 2022.08.29 sorted
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowgrid(k + 1);
        vector<vector<int>> colgrid(k + 1);
        vector<int> rowin(k + 1, 0);
        vector<int> colin(k + 1, 0);
        for(auto& rc : rowConditions) {
            rowgrid[rc[0]].emplace_back(rc[1]);
            rowin[rc[1]]++;
        }
        for(auto& cc : colConditions) {
            colgrid[cc[0]].emplace_back(cc[1]);
            colin[cc[1]]++;
        }
        vector<vector<int>> res;// (k, vector<int>(k, 0))
        queue<int> rque;
        queue<int> cque;
        for(int i = 1; i <= k; i++) {
            if(rowin[i] == 0) {
                rque.push(i);
            }
            if(colin[i] == 0) {
                cque.push(i);
            }
        }
        if(rque.empty() || cque.empty()) {
            return res;
        }
        int idx = 0;
        vector<int> rpath(k + 1, -1);
        vector<int> cpath(k + 1, -1);
        while(!rque.empty()) {
            int u = rque.front();
            rque.pop();
            rpath[u] = idx;
            idx++;
            for(auto& v : rowgrid[u]) {
                rowin[v]--;
                if(rowin[v] == 0) {
                    rque.push(v);
                }
            }
        }
        idx = 0;
        while(!cque.empty()) {
            int u = cque.front();
            cque.pop();
            cpath[u] = idx;
            idx++;
            for(auto& v : colgrid[u]) {
                colin[v]--;
                if(colin[v] == 0) {
                    cque.push(v);
                }
            }
        }
        for(int i = 1; i <= k; i++) {
            if(rowin[i] != 0 || colin[i] != 0) {
                return res;
            }
        }
        res.resize(k, vector<int>(k, 0));
        unordered_set<int> rset;
        unordered_set<int> cset;
        for(auto& r : rpath) {
            rset.insert(r);
        }
        for(auto& c : cpath) {
            cset.insert(c);
        }
        idx = 0;
        for(int i = 1; i <= k; i++) {
            if(rpath[i] == -1) {
                while(rset.count(idx)) {
                    idx++;
                }
                rpath[i] = idx;
            }
        }
        idx = 0;
        for(int i = 1; i <= k; i++) {
            if(cpath[i] == -1) {
                while(cset.count(idx)) {
                    idx++;
                }
                cpath[i] = idx;
            }
        }
        for(int i = 1; i <= k; i++) {
            res[rpath[i]][cpath[i]] = i;
        }
        return res;
    }
};