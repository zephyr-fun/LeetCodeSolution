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

// 2022.06.09
// diff
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        vector<int> res(n, 0);
        for(auto booking : bookings) {
            int left = booking[0] - 1;
            int right = booking[1] - 1;
            int delta = booking[2];
            diff[left] += delta;
            if(right + 1 < n) {
                diff[right + 1] -= delta;
            }
        }
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cur += diff[i];
            res[i] = cur;
        }
        return res;
    }
};

// 2022.06.29
// diff arrays
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n + 1, 0);
        vector<int> res(n, 0);
        int m = bookings.size();
        for(int i = 0; i < m; i++) {
            diff[bookings[i][0] - 1] += bookings[i][2];
            diff[bookings[i][1]] -= bookings[i][2];
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += diff[i];
            res[i] = sum;
        }
        return res;
    }
};