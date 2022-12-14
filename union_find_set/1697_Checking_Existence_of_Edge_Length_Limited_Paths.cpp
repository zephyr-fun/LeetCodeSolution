// 2022.12.14
// https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/solution/jian-cha-bian-chang-du-xian-zhi-de-lu-ji-c756/
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1, 0), rank(n + 1, 0), size(n + 1, 1) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if(parent[u] != u) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
            size[pu] += size[pv];
        }
        return true;
    }

    int getSize(int u) {
        int pu = Find(u);
        return size[pu];
    }

    bool connected(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        return pu == pv;
    }

private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        // 将 queries 按照边权限制从小到大排序
        vector<int> qid(queries.size());
        iota(qid.begin(), qid.end(), 0);
        sort(qid.begin(), qid.end(), [&](int i, int j) {
            return queries[i][2] < queries[j][2];
        });
        
        // 将 edgeList 按照边权从小到大排序
        sort(edgeList.begin(), edgeList.end(), [](const auto& e1, const auto& e2) {
            return e1[2] < e2[2];
        });
        
        // 并查集
        UnionFindSet set(n);
        
        int i = 0;
        vector<bool> res(queries.size());
        for(int query: qid) {
            // 往并查集中添加边直到边权关系 dis_i < limit_j 不满足
            while(i < edgeList.size() && edgeList[i][2] < queries[query][2]) {
                set.Union(edgeList[i][0], edgeList[i][1]);
                i++;
            }
            // 使用并查集判断连通性
            res[query] = set.connected(queries[query][0], queries[query][1]);
        }
        return res;
    }
};