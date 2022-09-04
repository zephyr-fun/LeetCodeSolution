// 2022.08.29 sorted
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        long sum = 0L;
        for(int& x : nums) {
            if(x >= 0) {
                sum += x;
            }
            else {
               x = -x; 
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<long, int>> pq;
        pq.emplace(sum, 0);
        while(--k) {
            auto[sum, i] = pq.top();
            pq.pop();
            if(i < nums.size()) {
                pq.emplace(sum - nums[i], i + 1); // 保留 nums[i-1]
                if(i) {
                    pq.emplace(sum - nums[i] + nums[i - 1], i + 1); // 不保留 nums[i-1]，把之前减去的加回来
                }
            }
        }
        return pq.top().first;
    }
};