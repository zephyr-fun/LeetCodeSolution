class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0){
            return res;
        }
        sort(nums.begin(), nums.end());
        if(nums[0] > 0){
            return res;
        }
        for(int i = 0; i < nums.size(); i++){

            int temp = 0 - nums[i];
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right){
                if(nums[left] + nums[right] > temp){
                    right--;
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                else if(nums[left] + nums[right] < temp){
                    left++;
                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                }
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left + 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[left - 1]){
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return res;
    }
};
// 2022.03.29
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0){
            return res;
        }
        sort(nums.begin(), nums.end());
        if(nums[0] > 0){
            return res;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int left = i + 1;
            int right = nums.size() - 1;
            int temp = 0 - nums[i];
            while(left < right){
                if(nums[left] + nums[right] > temp){
                    right--;
                    while(right > left && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                else if(nums[left] + nums[right] < temp){
                    left++;
                    while(right > left && nums[left] == nums[left - 1]){
                        left++;
                    }
                }
                else{
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(right > left && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(right > left && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

// 2022.04.18
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) {
            return res;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int temp = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while(left < right) {
                if(nums[left] + nums[right] < temp) {
                    left++;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
                else if(nums[left] + nums[right] > temp) {
                    right--;
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else {
                    res.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};