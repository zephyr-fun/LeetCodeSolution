// 2022.03.31
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
            int temp = 0 - nums[i];
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
                    // nums[left] + nums[right] == temp
                    res.push_back({nums[i], nums[left], nums[right]});
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
        return res;
    }
};

// 2022.07.06
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        if(nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        if(nums[0] > 0) {
            return res;
        }
        for(int i = 0; i < n; i++) {
            // remove repeat
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int temp = 0 - nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                if(nums[left] + nums[right] < temp) {
                    left++;
                    // remove repeat
                    while(nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                }
                else if(nums[left] + nums[right] > temp) {
                    right--;
                    // remove repeat
                    while(nums[right] == nums[right + 1] && left < right) {
                        right--;
                    }
                }
                else {
                    vector<int> path;
                    path.emplace_back(nums[i]);
                    path.emplace_back(nums[left]);
                    path.emplace_back(nums[right]);
                    res.emplace_back(path);
                    left++;
                    // remove repeat
                    while(nums[left] == nums[left - 1] && left < right) {
                        left++;
                    }
                    right--;
                    // remove repeat
                    while(nums[right] == nums[right + 1] && left < right) {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

// 2022.10.08
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < n - 2; i++) {
            if(i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = 0 - nums[i];
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                if(nums[left] + nums[right] > target) {
                    right--;
                    while(left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
                else if(nums[left] + nums[right] < target) {
                    left++;
                    while(left < right && nums[left] == nums[left - 1]) {
                        left++;
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