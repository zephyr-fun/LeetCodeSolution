// 2022.07.11
// dfs traversal prefix tree
class Solution {
public:
    long getCnt(long prefix, long n) {
        long cur = prefix;
        long next = prefix + 1;
        long cnt = 0;
        while(cur <= n) {
            cnt += min(next, n + 1) - cur;
            cur *= 10;
            next *= 10;
        }
        return cnt;
    }
    int findKthNumber(int n, int k) {
        long p = 1;
        long prefix = 1;
        while(p < k) {
            long cnt = getCnt(prefix, n);
            if(p + cnt > k) {
                prefix *= 10;
                p++;
            }
            else {
                prefix++;
                p += cnt;
            }
        }
        return prefix;
    }
};