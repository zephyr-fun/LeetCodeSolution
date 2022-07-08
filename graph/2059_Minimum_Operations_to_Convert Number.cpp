// 2022.07.08
// plain bfs
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        queue<pair<int, int>> que;
        que.push({start, 0});
        unordered_set<int> set;
        set.insert(start);
        while(!que.empty()) {
            auto [cur, step] = que.front();
            que.pop();
            for(int i = 0; i < n; i++) {
                if(!set.count(cur + nums[i])) {
                    if(cur + nums[i] == goal) {
                        return step + 1;
                    }
                    if(cur + nums[i] >= 0 && cur + nums[i] <= 1000) {
                        set.insert(cur + nums[i]);
                        que.push({cur + nums[i], step + 1});
                    }
                }
                if(!set.count(cur - nums[i])) {
                    if(cur - nums[i] == goal) {
                        return step + 1;
                    }
                    if(cur - nums[i] >= 0 && cur - nums[i] <= 1000) {
                        set.insert(cur - nums[i]);
                        que.push({cur - nums[i], step + 1});
                    }
                }
                if(!set.count(cur ^ nums[i])) {
                    if((cur ^ nums[i]) == goal) {
                        return step + 1;
                    }
                    if((cur ^ nums[i]) >= 0 && (cur ^ nums[i]) <= 1000) {
                        set.insert(cur ^ nums[i]);
                        que.push({cur ^ nums[i], step + 1});
                    }
                }
            }
        }
        return -1;
    }
};

// optim code, not algorithm
