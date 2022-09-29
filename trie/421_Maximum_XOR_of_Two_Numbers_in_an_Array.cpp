// 2022.08.16
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

    int findMaximumXOR(vector<int>& nums) {
        son.push_back({0, 0});
        int res = 0;
        for(auto& num : nums) {
            res = max(res, query(num));
            insert(num);
        }
        return res;
    }
};

// 2022.08.29
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

    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        son.push_back({0, 0});
        for(auto& num : nums) {
            res = max(res, query(num));
            insert(num);
        }
        return res;
    }
};

// 2022.09.29
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

    int findMaximumXOR(vector<int>& nums) {
        son.push_back({0, 0});
        int res = 0;
        for(auto& num : nums) {
            res = max(res, query(num));
            insert(num);
        }
        return res;
    }
};