// 2022.05.21
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size() / 2;
        int map[10007];
        memset(map, 0, sizeof(map));
        for(int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
            if(map[nums[i]] > 1) {
                return nums[i];
            }
        }
        return -1;
    }
};