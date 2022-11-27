// 2022.11.27
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        vector<int> gc(m);
        for (int i = 0; i < n; i ++ ) {
            int id = group[i];
            if (id != -1) gc[id] ++ ;
            else {
                gc.push_back(1);
                group[i] = m ++ ;
            }
        }

        vector<vector<int>> g1(n), g2(m);
        vector<int> d1(n), d2(m);
        for (int i = 0; i < n; i ++ ) {
            for (int j: beforeItems[i]) {
                g1[j].push_back(i);
                d1[i] ++ ;
                int a = group[i], b = group[j];
                if (a != b) {
                    g2[b].push_back(a);
                    d2[a] ++ ;
                }
            }
        }

        queue<int> q;
        for (int i = 0; i < m; i ++ ) {
            if (!d2[i]) {
                q.push(i);
            }
        }
        int cnt = 0, cur = 0;
        vector<int> pos(m);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++ ;
            pos[t] = cur;
            cur += gc[t];
            for (auto j: g2[t]) {
                if ( -- d2[j] == 0) {
                    q.push(j);
                }
            }
        }

        if (cnt != m) return {};
        for (int i = 0; i < n; i ++ ) {
            if (!d1[i]) {
                q.push(i);
            }
        }

        cnt = 0;
        vector<int> res(n);
        while (q.size()) {
            auto t = q.front();
            q.pop();
            cnt ++ ;
            int k = group[t];
            res[pos[k] ++ ] = t;
            for (auto j: g1[t]) {
                if ( -- d1[j] == 0) {
                    q.push(j);
                }
            }
        }

        if (cnt != n) return {};
        return res;
    }
};