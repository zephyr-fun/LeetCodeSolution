// 2022.10.01
// FenwickTree + binary search
class FenwickTree {
public:
    FenwickTree(int n) : sums_(n + 1, 0) {}

    void update(int idx, int delta) {
        while(idx < sums_.size()) {
            sums_[idx] += delta;
            idx += lowbit(idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while(idx > 0) {
            sum += sums_[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
private:
    vector<int> sums_;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};
class LUPrefix {
public:
    int n;
    FenwickTree tree;
    LUPrefix(int n_) : n(n_), tree(n) {
        
    }
    
    void upload(int video) {
        tree.update(video, 1);
    }
    
    int longest() {
        int left = 1;
        int right = n;
        int res = 0;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(tree.query(mid) >= mid) {
                res = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */