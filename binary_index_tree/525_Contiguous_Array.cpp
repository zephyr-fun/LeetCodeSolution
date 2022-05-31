// 2022.05.16
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map({{0, -1}});
        int cur = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            nums[i] == 0 ? cur-- : cur++;
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

// use array replace vector, faster
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

// 2022.05.31
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