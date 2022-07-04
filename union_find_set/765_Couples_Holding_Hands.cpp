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

// 2022.07.04
// error version, explain the reason later
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> map(n, -1);
        for(int i = 0; i < n; i++) {
            map[row[i]] = i / 2;
        }
        int resa = 0;
        int resb = 0;
        set<pair<int, int>> set;
        for(int i = 0; i < n; i += 2) {
            if(map[i] != map[i + 1]) {
                if(!set.count({map[i], map[i + 1]}) && !set.count({map[i + 1], map[i]})) {
                    resa += 1;
                    set.insert({map[i], map[i + 1]});
                }
                else {
                    resa -= 1;
                    resb += 1;
                }
            }
        }
        return max(0, resa - 1) + resb;
    }
};

// 解析上述方法不对的原因，每个人按自身的标号可以有一个情侣组标号，比如0，1都属于0号组
// 假设三对情侣‘相互’坐错位置，那么需要两次交换，n对情侣满足分别相互坐错位置时需要的交换次数是n - 1
// 上述条件是两两相互，不存在可以单独化简的子部分
// 举个例子
// 1 4 0 5 8 7 6 3 2 9
// 0 2 0 2 4 3 3 1 1 4
// 可以看到0202是一个两联通，433114是一个三联通，因此总数等于(2 - 1) + (3 - 1) = 3
// 因此想到并查集来表示情侣组的联通，并查集的性质又保证了结果不需要化简，上述方法的问题就是只考虑了2联通和3联通
// 剩下的四联通及以上都是没有的，所以不对

// correct version with union find set
class UnionFindSet {
public:
    UnionFindSet(int n) : rank(n + 1, 0), parent(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
    }

    int Find(int u) {
        if(u != parent[u]) {
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
        }
        else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        }
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
private:
    vector<int> rank;
    vector<int> parent;
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int res = 0;
        int n = row.size();
        int m = n / 2;
        UnionFindSet set(m);
        for(int i = 0; i < n; i += 2) {
            if(set.Union(row[i] / 2, row[i + 1] / 2)) {
                res++;
            }
        }
        return res;
    }
};