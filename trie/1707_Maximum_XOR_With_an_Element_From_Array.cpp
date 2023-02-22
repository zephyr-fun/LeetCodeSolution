// 2022.09.29
// offline
class Solution {
public:
    vector<vector<int>> son;

    void insert(int num) {
        int p = 0;
        for(int i = 30; i >= 0; i--) {
            int u = (num >> i) & 1;
            if(!son[p][u]) {
                son[p][u] = son.size();
                son.push_back({0, 0});
            }
            p = son[p][u];
        }
    }

    int query(int num) {
        int p = 0;
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            int u = (num >> i) & 1;
            if(son[p][!u]) {
                res = res * 2 + !u;
                p = son[p][!u];
            }
            else {
                res = res * 2 + u;
                p = son[p][u];
            }
        }
        return res ^ num;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        son.push_back({0, 0});
        for(int i = 0; i < n; i++) {
            queries[i].emplace_back(i);
        }
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [](auto& a, auto& b) {
            return a[1] < b[1];
        });
        int idx = 0;
        vector<int> res(n, -1);
        for(auto& q : queries) {
            while(idx < nums.size() && nums[idx] <= q[1]) {
                insert(nums[idx]);
                idx++;
            }
            if(idx == 0) {
                res[q[2]] = -1;
            }
            else {
                res[q[2]] = query(q[0]);
            }
        }
        return res;
    }
};

// online
class Solution {
public:
    vector<vector<int>> son;

    void insert(int num) {
        int p = 0;
        for(int i = 30; i >= 0; i--) {
            int u = (num >> i) & 1;
            if(!son[p][u]) {
                son[p][u] = son.size();
                son.push_back({0, 0, 0x3f3f3f3f, 0x3f3f3f3f});
            }
            son[p][u + 2] = min(son[p][u + 2], num);
            p = son[p][u];
        }
    }

    int query(int num, int up) {
        int p = 0;
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            int u = (num >> i) & 1;
            if(son[p][!u] && son[p][!u + 2] <= up) {
                res = res * 2 + !u;
                p = son[p][!u];
            }
            else if(son[p][u] && son[p][u + 2] <= up) {
                res = res * 2 + u;
                p = son[p][u];
            }
            else {
                return -1;
            }
        }
        return res ^ num;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        son.push_back({0, 0, 0x3f3f3f3f, 0x3f3f3f3f});
        vector<int> res(n, -1);
        for(int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
        }
        for(int i = 0; i < n; i++) {
            res[i] = query(queries[i][0], queries[i][1]);
        }
        return res;
    }
};

// 2023.02.22
class Solution {
public:
    vector<vector<int>> son;

    void insert(int num) {
        int p = 0;
        for(int i = 30; i >= 0; i--) {
            int u = (num >> i) & 1;
            if(!son[p][u]) {
                son[p][u] = son.size();
                son.push_back({0, 0});
            }
            p = son[p][u];
        }
    }

    int query(int num) {
        int p = 0;
        int res = 0;
        for(int i = 30; i >= 0; i--) {
            int u = (num >> i) & 1;
            if(son[p][!u]) {
                res = res * 2 + !u;
                p = son[p][!u];
            }
            else {
                res = res * 2 + u;
                p = son[p][u];
            }
        }
        return num ^ res;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        son.push_back({0, 0});
        for(int i = 0; i < queries.size(); i++) {
            queries[i].emplace_back(i);
        }
        sort(nums.begin(), nums.end());
        sort(queries.begin(), queries.end(), [] (vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });
        int n = nums.size();
        int m = queries.size();
        vector<int> res(m, -1);
        int idx = 0;
        for(auto& q : queries) {
            while(idx < n && nums[idx] <= q[1]) {
                insert(nums[idx]);
                idx++;
            }
            if(idx == 0) {
                res[q[2]] = -1;
            }
            else {
                res[q[2]] = query(q[0]);
            }
        }
        return res;
    }
};