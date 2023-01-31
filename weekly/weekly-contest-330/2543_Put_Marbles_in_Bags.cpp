// 2023.01.30
typedef long long LL;
class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<LL> w(n - 1, 0);
        for(int i = 0; i < n - 1; i++) {
            w[i] = (LL)weights[i] + weights[i + 1];
        }
        sort(w.begin(), w.end());
        LL maxK = 0;
        LL minK = 0;
        for(int i = 0; i < k - 1; i++) {
            minK += w[i];
        }
        for(int i = n - 2; i > n - 1 - k; i--) {
            maxK += w[i];
        }
        return maxK - minK;
    }
};

// optim space
class Solution {
public:
    long long putMarbles(vector<int> &wt, int k) {
        int n = wt.size();
        for(int i = 0; i < n - 1; i++) {
            wt[i] += wt[i + 1];
        }
        sort(wt.begin(), wt.end() - 1); // 相当于去掉最后一个数
        long res = 0;
        for(int i = 0; i < k - 1; ++i) {
            res += wt[n - 2 - i] - wt[i];
        }
        return res;
    }
};

// optim O(n)
class Solution {
public:
    long long putMarbles(vector<int> &wt, int k) {
        if(--k == 0) {
            return 0;
        }
        int n = wt.size() - 1;
        for(int i = 0; i < n; i++) {
            wt[i] += wt[i + 1];
        }
        wt.pop_back();
        long res = 0;
        nth_element(wt.begin(), wt.begin() + k, wt.end());
        for(int i = 0; i < k; i++) {
            res -= wt[i];
        }   
        nth_element(wt.begin(), wt.end() - k, wt.end());
        for(int i = 0; i < k; i++) {
            res += wt[n - 1 - i];
        } 
        return res;
    }
};