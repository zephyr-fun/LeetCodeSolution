// 2022.06.26
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
        if(ranks_[pu] < ranks_[pv]) {
            parent_[pu] = pv;
        }
        else if(ranks_[pu] > ranks_[pv]) {
            parent_[pv] = pu;
        }
        else {
            parent_[pv] = pu;
            ranks_[pu]++;
        }
        return true;
    }

private:
    vector<int> ranks_;
    vector<int> parent_;
};
class Solution {
public:
    long long countPairs(int n_, vector<vector<int>>& edges) {
        UnionFindSet set(n_);
        long long n = n_;
        for(auto edge : edges){
            set.Union(edge[0],edge[1]);
        }
        unordered_map<int, int> map;
        for(int i = 0;i<n;i++){
            map[set.Find(i)]++;
        }
        vector<pair<int,int>> temp;
        for(auto it:map){
            temp.emplace_back(it);
        }
        sort(temp.begin(),temp.end(),[](pair<int,int>& a,pair<int,int>& b){
            return a.second > b.second;
        });
        long long res = 0;
        for(auto tp:temp){
            n -= tp.second;
            res += (long long)(n*tp.second);
        }
        return res;
    }
};