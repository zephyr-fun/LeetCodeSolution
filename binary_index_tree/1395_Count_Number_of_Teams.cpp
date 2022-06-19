// 2022.06.19
// dfs TLE
class Solution {
public:
    int res = 0;
    int n;
    void dfs(vector<int>& rating, int idx, int curNum) {
        if(curNum == 3) {
            res++;
            return ;
        }
        for(int i = idx + 1; i < n; i++) {
            if(rating[i] > rating[idx]) {
                dfs(rating, i, curNum + 1);
            }
        }
    }
    int numTeams(vector<int>& rating) {
        n = rating.size();
        for(int i = 0; i < n - 2; i++) {
            dfs(rating, i, 1);
        }
        reverse(rating.begin(), rating.end());
        for(int i = 0; i < n - 2; i++) {
            dfs(rating, i, 1);
        }
        return res;
    }
};

// FenwickTree
class FenwickTree {
public:
    FenwickTree(int n): sum(n + 1, 0) {}

    void update(int idx, int delta) {
        while(idx < sum.size()) {
            sum[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int query(int idx) {
        int res = 0;
        while(idx > 0) {
            res += sum[idx];
            idx -= lowbit(idx);
        }
        return res;
    }
private:
    vector<int> sum;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int N = 1e5 + 7;
        FenwickTree tree1(N);
        FenwickTree tree2(N);
        int res = 0;
        for(int i = 0; i < n; i++) {
            tree1.update(rating[i], 1);
        }
        for(int i = 0; i < n; i++) {
            tree1.update(rating[i], -1);
            res += tree2.query(rating[i] - 1) * (tree1.query(N - 1) - tree1.query(rating[i]));
            res += (tree2.query(N - 1) - tree2.query(rating[i])) * tree1.query(rating[i] - 1);
            tree2.update(rating[i], 1);
        }
        return res;
    }
};