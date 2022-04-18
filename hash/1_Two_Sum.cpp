class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
// 2022.03.29
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; //value, index
        for(int i = 0; i < nums.size(); i++){
            if(map.find(target - nums[i]) != map.end()){
                return {map[target - nums[i]], i};
            }
            else{
                map[nums[i]] = i;
            }
        }
        return {};
    }
};

// 2022.04.18
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++) {
            if(map.find(target - nums[i]) != map.end()) {
                return {map[target - nums[i]], i};
            }
            else {
                map[nums[i]] = i;
            }
        }
        return {};
    }
};