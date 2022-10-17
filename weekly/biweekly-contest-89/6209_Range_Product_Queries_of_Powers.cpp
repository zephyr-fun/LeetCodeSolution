// 2022.10.15
// https://blog.nowcoder.net/n/52aebc2e041a4c918ff17e4562ee5fdc
typedef long long LL;
class Solution {
public:
    const LL mod = 1e9 + 7;
    LL quickpow(LL x, LL y, LL MOD) {//快速幂，求逆元时使用
        LL bs = 1;
        while (y) {
            if (y & 1) {
                bs = (x * bs) % MOD;
            }
            x = (x * x) % MOD;
            y >>= 1;
        }
        return bs;
    }
    LL get_inv(LL x) {
        return quickpow(x, mod - 2, mod);//费马小定理求逆元
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> sq(31, 0);
        sq[0] = 1;
        for(int i = 1; i < 31; i++) {
            sq[i] = 2 * sq[i - 1];
        }
        vector<int> nums;
        int idx = 30;
        while(n) {
            while(idx > 0 && sq[idx] > n) {
                idx--;
            }
            n -= sq[idx];
            nums.emplace_back(sq[idx]);
        }
        reverse(nums.begin(), nums.end());
        n = nums.size();
        vector<LL> prefix(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1] % mod;
        }
        vector<int> res;
        for(auto& query : queries) {
            res.emplace_back(prefix[query[1] + 1] * get_inv(prefix[query[0]]) % mod);
        }
        return res;
    }
};

// 被数据范围忽悠了
// TsReaper version
class Solution {
    const int MAXP = 30;
    const int MOD = 1000000007;

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        // 计算 n 的二进制分解
        vector<int> vec;
        for (int i = 0; i <= MAXP; i++) if (n >> i & 1) vec.push_back(1 << i);

        vector<int> ans;
        for (auto &qry : queries) {
            // 暴力处理每个询问
            int L = qry[0], R = qry[1];
            long long t = 1;
            for (int i = L; i <= R; i++) t = t * vec[i] % MOD;
            ans.push_back(t);
        }
        return ans;
    }
};