// 2022.08.22
// map
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int res = 0;
        unordered_map<int, int> map; // value, first time
        map[0] = -1;
        for(int i = 0; i < n; i++) {
            cur = nums[i] == 0 ? cur - 1 : cur + 1;
            if(map.count(cur)) {
                res = max(res, i - map[cur]);
            }
            else {
                map[cur] = i;
            }
        }
        return res;
    }
};

// optim array
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        // hash_map records <state, index>, when state appear first time, so that keep the index minimum
        int map[200007];
        memset(map, 0x3f, sizeof(map));
        int M = 200007 / 2;
        map[0 + M] = -1;
        int curState = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] == 0 ? curState-- : curState++;
            if(map[curState + M] != 0x3f3f3f3f) {
                res = max(res, i - map[curState + M]);
            }
            else {
                map[curState + M] = i;
            }
        }
        return res;
    }
};

// 2022.08.30
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int map[200005] = {0};
        int mod = 1e5;
        int cur = 0;
        memset(map, 0x3f, sizeof(map));
        map[mod] = -1;
        int n = nums.size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            cur += nums[i] == 0 ? -1 : 1;
            if(map[cur + mod] == 0x3f3f3f3f) {
                map[cur + mod] = i;
            }
            else {
                res = max(i - map[cur + mod], res);
            }
        }
        return res;
    }
};