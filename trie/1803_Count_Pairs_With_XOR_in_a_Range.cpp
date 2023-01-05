// 2023.01.05
// hash map
class Solution {
public:
    int countPairs(vector<int> &nums, int low, int high) {
        int res = 0;
        unordered_map<int, int> cnt;
        for(auto num: nums) {
            cnt[num]++;
        }
        for(++high; high; high >>= 1, low >>= 1) {
            unordered_map<int, int> nxt;
            for(auto &[x, c] : cnt) {
                if (high & 1 && cnt.count(x ^ (high - 1))) {
                    res += c * cnt[x ^ (high - 1)];
                }
                if (low & 1 && cnt.count(x ^ (low - 1))) {
                    res -= c * cnt[x ^ (low - 1)];
                }
                nxt[x >> 1] += c;
            }
            cnt = move(nxt);
        }
        return res / 2;
    }
};

// trie too