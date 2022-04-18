class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() == 0){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int temp = target - nums[i] - nums[j];
                int left = j + 1;
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
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while(left < right && nums[right] == nums[right - 1]){
                            right--;
                        }
                        while(left < right && nums[left] == nums[left + 1]){
                            left++;
                        }
                        right--;
                        left++;
                    }
                }
            }
        }
        return res;
    }
};
// 2022.03.29
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() == 0){
            return res;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++){
                if(j > i + 1 && nums[j] == nums[j - 1]){
                    continue;
                }
                int temp = target - nums[i] - nums[j];
                int left = j + 1;
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
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while(left < right && nums[left] == nums[left - 1]){
                            left++;
                        }
                        while(left < right && nums[right] == nums[right + 1]){
                            right--;
                        }
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        if(nums.size() == 0) {
            return res;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for(int j = i + 1; j < nums.size(); j++) {
                if(j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                int temp = target - nums[i] - nums[j];
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
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
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
        }
        return res;
    }
};