// 2022.05.18
// prefix array
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> prefix(size + 1, 0);
        vector<int> res;
        for(int i = 1; i <= size; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        for(auto query : queries) {
            int left = query[0];
            int right = query[1];
            res.push_back(prefix[right + 1] ^ prefix[left]);
        }
        return res;
    }
};

// BIT
class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1) {}

    void update(int i, int delta) {
        while(i < sums_.size()) {
            sums_[i] ^= delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int res = 0;
        while(i > 0) {
            res ^= sums_[i];
            i -= lowbit(i);
        }
        return res;
    }

private:
    vector<int> sums_;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        FenwickTree prefixTree(size);
        vector<int> res;
        for(int i = 0; i < size; i++) {
            prefixTree.update(i + 1, arr[i]);
        }
        for(auto query : queries) {
            int left = query[0];
            int right = query[1];
            res.push_back(prefixTree.query(right + 1) ^ prefixTree.query(left));
        }
        return res;
    }
};

// 2022.06.09
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        int m = queries.size();
        vector<int> prefix(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] ^ arr[i - 1];
        }
        vector<int> res;
        for(auto query : queries) {
            int left = query[0];
            int right = query[1];
            res.push_back(prefix[right + 1] ^ prefix[left]);
        }
        return res;
    }
};