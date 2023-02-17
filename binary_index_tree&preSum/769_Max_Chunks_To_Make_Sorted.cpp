// 2022.10.13
class FenwickTree {
public:
    FenwickTree(int n) : sums(n + 1) {}

    void update(int idx, int delta) {
        while(idx < sums.size()) {
            sums[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += sums[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
private:
    vector<int> sums;
    static inline int lowbit(int x) {
        return x & -x;
    }
};
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        FenwickTree tree(n);
        int res = 0;
        int last = 0;
        for(int i = 0; i < n; i++) {
            tree.update(arr[i] + 1, 1);
            if(tree.query(i + 1) - tree.query(last) == i - last + 1) {
                res++;
                last = i;
            }
        }
        return res;
    }
};

// optim 1
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int minVal = n;
        int maxVal = -1;
        int res = 0;
        for(int i = 0, j = 0; i < n; i++) {
            minVal = min(minVal, arr[i]);
            maxVal = max(maxVal, arr[i]);
            if(i == maxVal && j == minVal) {
                res++;
                j = i + 1;
                minVal = n;
                maxVal = -1;
            }
        }
        return res;
    }
};

// optim 2
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cnt1 = 0;
        int cnt2 = 0;
        int n = arr.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            cnt1 += arr[i];
            cnt2 += i;
            if(cnt1 == cnt2) {
                res++;
            }
        }
        return res;
    }
};