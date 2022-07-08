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

// optim code struct, not algorithm
class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int n = nums.size();
        unordered_set <int> set;
        queue<pair<int, int>> que;
        que.push({start, 0});
        set.insert(start);
        while(!que.empty()) {
            auto [cur, step] = que.front();
            que.pop();
            for(int i = 0; i < n; i++) {
                int temp[3] = {cur + nums[i], cur - nums[i], cur ^ nums[i]};
                for(int j = 0; j < 3; j++) {
                    if(temp[j] == goal) {
                        return step + 1;
                    }
                    if(set.count(temp[j]) || temp[j] > 1000 || temp[j] < 0) {
                        continue;
                    }
                    set.insert(temp[j]);
                    que.push({temp[j], step + 1});
                }
            }
        }
        return -1;
    }
};

// bidirection bfs
// can't mix two update step
class Solution {
public:
    vector<int> nums;
    int minimumOperations(vector<int>& nums_, int start, int goal) {
        nums = nums_;
        int n = nums.size();
        unordered_map<int, int> smap;
        unordered_map<int, int> gmap;
        queue<int> sque;
        queue<int> gque;
        smap[start] = 0;
        gmap[goal] = 0;
        sque.push(start);
        gque.push(goal);
        while(!sque.empty() && !gque.empty()) {
            int t = 0;
            if(sque.size() <= gque.size()) {
                t = update(sque, gque, smap, gmap);
            }
            else {
                t = update(gque, sque, gmap, smap);
            }
            if(t != -1) {
                return t;
            }
        }
        return -1;
    }
    int update(queue<int>& que1, queue<int>& que2, unordered_map<int, int>& map1, unordered_map<int, int>& map2) {
        int size = que1.size();
        while(size--) {
            int cur = que1.front();
            que1.pop();
            int step = map1[cur];
            for(int i = 0; i < nums.size(); i++) {
                int temp[3] = {cur + nums[i], cur - nums[i], cur ^ nums[i]};
                for(int j = 0; j < 3; j++) {
                    if(map2.count(temp[j])) {
                        return map2[temp[j]] + step + 1;
                    }
                    if(map1.count(temp[j]) || temp[j] > 1000 || temp[j] < 0) {
                        continue;
                    }
                    map1[temp[j]] = step + 1;
                    que1.push(temp[j]);
                }
            }
        }
        return -1;
    }
};