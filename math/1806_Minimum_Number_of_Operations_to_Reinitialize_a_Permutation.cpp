// 2023.01.09
// simulate
class Solution {
public:
    int n;
    vector<int> original;
    bool check(vector<int>& a) {
        for(int i = 0; i < n; i++) {
            if(a[i] != original[i]) {
                return false;
            }
        }
        return true;
    }
    int reinitializePermutation(int _n) {
        n = _n;
        vector<int> perm(n, 0);
        for(int i = 0; i < n; i++) {
            perm[i] = i;
        }
        original = perm;
        vector<int> arr(n, 0);
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                arr[i] = perm[i / 2];
            }
            else {
                arr[i] = perm[n / 2 + (i - 1) / 2];
            }
        }
        int res = 1;
        while(!check(arr)) {
            perm = arr;
            for(int i = 0; i < n; i++) {
                if(i % 2 == 0) {
                    arr[i] = perm[i / 2];
                }
                else {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            res++;
        }
        return res;
    }
};

// math
// https://leetcode.cn/problems/minimum-number-of-operations-to-reinitialize-a-permutation/solution/by-lcbin-68iy/
class Solution {
public:
    int reinitializePermutation(int n) {
        int res = 0;
        for(int i = 1; ; ) {
            res++;
            if(i < (n >> 1)) {
                i <<= 1;
            }
            else {
                i = (i - (n >> 1)) << 1 | 1;
            }
            if(i == 1) {
                return res;
            }
        }
    }
};