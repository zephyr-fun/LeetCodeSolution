// 2022.04.06
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;
        if(nums.size() == 1){
            return true;
        }
        for(int i = 0; i <= cover; i++){
            cover = max(i + nums[i], cover);
            if(cover >= nums.size() - 1){
                return true;
            }
        }
        return false;
    }
};

// 2022.07.25
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int cover = 0;
        for(int i = 0; i <= cover; i++) {
            cover = max(cover, i + nums[i]);
            if(cover >= n - 1) {
                return true;
            }
        }
        return false;
    }
};