// 2022.06.08
class UnionFindSet {
public:
    UnionFindSet(int n): rank_(n + 1, 0), parent_(n + 1, 0) {
        for(int i = 0; i < parent_.size(); i++) {
            parent_[i] = i;
        }
    }

    int Find(int u) {
        if(u != parent_[u]) {
            parent_[u] = Find(parent_[u]);
        }
        return parent_[u];
    }

    bool Union(int u, int v) {
        int pu = Find(u);
        int pv = Find(v);
        if(pu == pv) {
            return false;
        }
        if(rank_[pu] < rank_[pv]) {
            parent_[pu] = pv;
        }
        else if(rank_[pu] > rank_[pv]) {
            parent_[pv] = pu;
        }
        else {
            parent_[pv] = pu;
            rank_[pu]++;
        }
        return true;
    }
private:
    vector<int> rank_;
    vector<int> parent_;
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int m = n / 2;
        UnionFindSet set(m);
        int cnt = 0;
        for(int i = 0; i < n; i += 2) {
            if(set.Union(row[i] / 2, row[i + 1] / 2)) {
                cnt++;
            }
        }
        return cnt;
    }
};