// 2022.05.12
// Fenwick tree
class FenwickTree {
public:
    FenwickTree(int n): sums_(n + 1, 0) {}

    void update(int i, int delta) {
        while(i < sums_.size()) {
            sums_[i] += delta;
            i += lowbit(i);
        }
    }

    int query(int i) {
        int sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    vector<int> sums_;
    static inline int lowbit(int x) {
        return x & (-x);
    }
};
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        FenwickTree diffTree(n);
        for(auto & book : bookings) {
            int left = book[0];
            int right = book[1];
            int seats = book[2];
            diffTree.update(left, seats);
            diffTree.update(right + 1, -seats);
        }
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            res[i] = diffTree.query(i + 1);
        }
        return res;
    }
};

// difference arrays
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 2, 0); // n + 2
        for(auto& book : bookings) {
            int left = book[0];
            int right = book[1];
            int seats = book[2];
            diff[left] += seats;
            diff[right + 1] -= seats;
        }
        vector<int> res(n, 0);
        res[0] = diff[1];
        for(int i = 1; i < n; i++) {
            res[i] = res[i - 1] + diff[i + 1];
        }
        return res;
    }
};