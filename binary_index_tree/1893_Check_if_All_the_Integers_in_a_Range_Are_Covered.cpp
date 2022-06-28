// 2022.05.17
// diff array
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(52, 0);
        for(int i = 0; i < ranges.size(); i++) {
            diff[ranges[i][0]]++;
            diff[ranges[i][1] + 1]--;
        }
        int cur = 0;
        for(int i = 0; i < 52; i++) {
            cur += diff[i];
            if(i >= left && i <= right && cur <= 0) {
                return false;
            }
        }
        return true;
    }
};

// plain BIT
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
        if(i >= sums_.size()) {
            i = sums_.size() - 1;
        }
        int sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> sums_;
};

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        FenwickTree diffTree(max(ranges[ranges.size() - 1][1], right) + 1);
        for(int i = 0; i < ranges.size(); i++) {
            vector<int> range = ranges[i];
            for(int j = ranges[i][0]; j <= ranges[i][1]; j++) {
                diffTree.update(j, 1);
            }
        }
        for(int i = left; i <= right; i++) {
            int cur = diffTree.query(i) - diffTree.query(i - 1);
            if(cur <= 0) {
                return false;
            }
        }
        return true;
    }
};

// drop repeat
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
        if(i >= sums_.size()) {
            i = sums_.size() - 1;
        }
        int sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> sums_;
};

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        unordered_set<int> set;
        FenwickTree diffTree(max(ranges[ranges.size() - 1][1], right) + 1);
        for(int i = 0; i < ranges.size(); i++) {
            vector<int> range = ranges[i];
            for(int j = ranges[i][0]; j <= ranges[i][1]; j++) {
                if(set.count(j) == 0) {
                    diffTree.update(j, 1);
                    set.insert(j);
                }
            }
        }
        if((diffTree.query(right) - diffTree.query(left - 1)) != (right - left + 1)) {
            return false;
        }
        return true;
    }
};

// 2022.05.31
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
        if(i >= sums_.size()) {
            i = sums_.size() - 1;
        }
        int sum = 0;
        while(i > 0) {
            sum += sums_[i];
            i -= lowbit(i);
        }
        return sum;
    }

private:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    vector<int> sums_;
};

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end(), [](vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        unordered_set<int> set; // drop repeat, avoid range overlap
        FenwickTree diffTree(max(ranges[ranges.size() - 1][1], right) + 1);
        for(int i = 0; i < ranges.size(); i++) {
            vector<int> range = ranges[i];
            for(int j = ranges[i][0]; j <= ranges[i][1]; j++) {
                if(set.count(j) == 0) {
                    diffTree.update(j, 1);
                    set.insert(j);
                }
            }
        }
        if((diffTree.query(right) - diffTree.query(left - 1)) != (right - left + 1)) {
            return false;
        }
        return true;
    }
};

// 2022.06.20
// diff array
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        vector<int> diff(57, 0);
        for(auto range : ranges) {
            diff[range[0]]++;
            diff[range[1] + 1]--;
        }
        int cur = 0;
        for(int i = 0; i < left; i++) {
            cur += diff[i];
        }
        for(int i = left; i <= right; i++) {
            cur += diff[i];
            if(cur <= 0) {
                return false;
            }
        }
        return true;
    }
};

// 2022.06.28
// cover = diff
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int cover[57];
        memset(cover, 0, sizeof(cover));
        for(auto range : ranges) {
            cover[range[0]]++;
            cover[range[1] + 1]--;
        }
        int cur = 0;
        for(int i = 1; i < left; i++) {
            cur += cover[i];
        }
        for(int i = left; i <= right; i++) {
            cur += cover[i];
            if(cur == 0) {
                return false;
            }
        }
        return true;
    }
};