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

// 2022.10.01
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        for(auto& num : nums) {
            if(num > 0) {
                sum += num;
            }
            else {
                num = -num;
            }
        }
        sort(nums.begin(), nums.end());
        priority_queue<pair<long long, int>> pque;
        pque.push(make_pair(sum, 0));
        while(--k) {
            auto [cur, i] = pque.top();
            pque.pop();
            if(i < n) {
                pque.push(make_pair(cur - nums[i], i + 1));
                if(i) {
                    pque.push(make_pair(cur - nums[i] + nums[i - 1], i + 1));
                }
            }
        }
        return pque.top().first;
    }
};