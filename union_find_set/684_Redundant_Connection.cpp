// 2022.06.04
class UnionFindSet {
public:
    UnionFindSet(int n) {
        ranks_ = vector<int>(n + 1, 0);
        parent_ = vector<int>(n + 1, 0);
        for(int i = 0; i < parent_.size(); i++) {
            parent_[i] = i;
        }
    }
    int Find(int u) {
        if(u != parent_[u]) {
            parent_[u] = Find(parent_[u]); // path compression
        }
        return parent_[u];
    }
    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(ranks_[pu] < ranks_[pv]) {
            parent_[pu] = pv;
        }
        else if(ranks_[pu] > ranks_[pv]) {
            parent_[pv] = pu;
        }
        else {
            parent_[pv] = pu;
            ranks_[pu] += 1;
        }
        return true;
    }
private:
    vector<int> ranks_;
    vector<int> parent_;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        UnionFindSet set(edges.size());
        for(const auto& edge : edges) {
            if(!set.Union(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};

// 2023.09.23
class UnionFindSet {
public:
    UnionFindSet(int n) : parent(n + 1, 0), rank(n + 1, 0), size(n + 1, 1) {
        for (int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if (u != parent[u]) {
            parent[u] = Find(parent[u]);
        }
        return parent[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if (pu == pv) {
            return false;
        }
        if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else if (rank[pv] < rank[pu]) {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
            rank[pu]++;
        }
        return true;
    }

private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFindSet set(n);
        for (auto& edge : edges) {
            if (!set.Union(edge[0], edge[1])) {
                return {edge[0], edge[1]};
            }
        }
        return vector<int>();
    }
};