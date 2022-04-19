// 2022.03.31
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int slow = 0;
        int fast = 0;
        while(fast < nums.size()){
            if(nums[slow] != nums[fast]){
                if(fast - slow > 1){
                    nums[slow + 1] = nums[fast];
                }
                slow++;
            }
            fast++;
        }
        return slow + 1;
    }
};

// 2022.04.19
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        while(slow <= fast && fast < nums.size()) {
            if(fast > 0 && nums[fast] == nums[fast - 1]) {
                fast++;
            }
            else {
                nums[slow] = nums[fast];
                slow++;
                fast++;
            }
        }
        return slow;
    }
};