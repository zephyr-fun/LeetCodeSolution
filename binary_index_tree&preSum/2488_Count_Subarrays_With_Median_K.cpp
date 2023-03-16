// 2023.03.16
// presum + hash
// 定义 presum[i] 为 [1, i] 的大于 k 减去小于 k 的数量
// k 为子数组的中位数的数学表达就是子数组中大于 k 的个数 - 小于 k 的个数 <= 1，(根据区间长度的奇偶性)
// presum 可以让求区间大于小于 k 的差值数量变为O(1)，但是遍历 i 之前的 j 仍然需要 O(n)
// 所以利用 hash 来优化，同时考虑子数组中一定需要存在 k ，
// 那么在加入 hash 值的时候，就可以考虑每当遇到一个 k 时，才将它之前的所有 presum 值加入到hash，这样后面检索的任意区间，都将包含至少一个 k ，符合要求
class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int last = 0;
        int sum[n + 1];
        memset(sum, 0, sizeof(sum));
        unordered_map<int, int> map;
        for(int i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + (nums[i - 1] > k ? 1 : nums[i - 1] < k ? -1 : 0);
            if(nums[i - 1] == k) {
                for(int j = last; j < i; j++) {
                    map[sum[j]]++;
                }
                last = i;
            }
            res += map[sum[i] - 1] + map[sum[i]];
        }
        return res;
    }
};