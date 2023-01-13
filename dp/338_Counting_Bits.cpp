// 2022.08.29
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        for(int i = 0; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};

// 2023.01.13
class Solution {
public:
    static inline int lowbit(int x) {
        return x & (-x);
    }
    int count(int x) {
        int res = 0;
        while(x > 0) {
            x -= lowbit(x);
            res++;
        }
        return res;
    }
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            res[i] = count(i);
        }
        return res;
    }
};

// dp
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(i & 1) {
                res[i] = res[i - 1] + 1;
            }
            else {
                res[i] = res[i >> 1];
            }
        }
        return res;
    }
};

// optim
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        for(int i = 0; i <= n; i++) {
            res[i] = res[i >> 1] + (i & 1);
        }
        return res;
    }
};