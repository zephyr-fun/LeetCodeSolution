// 2022.07.30
class UnionFindSet {
public:
    UnionFindSet(int n, vector<int>& nums) : parent(n + 1), rank(n + 1, 0), size(n + 1, 0) {
        for(int i = 0; i < parent.size(); i++) {
            parent[i] = i;
        }
        for(auto num : nums) {
            size[num] = 1;
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
            size[pv] += size[pu];
        }
        else if(rank[pu] > rank[pv]) {
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

    int getSize(int u) {
        int pu = Find(u);
        return size[pu];
    }

private:
    vector<int> parent;
    vector<int> rank;
    vector<int> size;
};
class Solution {
public:
    // int gcd(int a, int b) {
    //     return b == 0 ? gcd(b, a % b) : a;
    // }
    int largestComponentSize(vector<int>& nums) {
        int maxNum = -0x3f3f3f3f;
        for(int num : nums) {
            maxNum = max(maxNum, num);
        }
        UnionFindSet set(maxNum + 1, nums);
        for(int num : nums) {
            for(int i = sqrt(num); i >= 2; i--) {
                if(num % i == 0) {
                    set.Union(num, i);
                    set.Union(num, num / i);
                }
            }
        }
        int res = 0;
        for(int num : nums) {
            res = max(res, set.getSize(num));
        }
        return res;
    }
};