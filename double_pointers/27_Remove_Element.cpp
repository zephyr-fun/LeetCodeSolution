// 2022.03.31
// fast slow pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

// directional pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val){
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            while(left <= right && nums[left] != val){
                left++;
            }
            while(left <= right && nums[right] == val){
                right--;
            }
            if(left < right){
                nums[left] ^= nums[right];
                nums[right] ^= nums[left];
                nums[left] ^= nums[right];
                left++;
                right--;
            }
        }
        return left;
    }
};

// 2022.04.19
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++) {
            if(nums[fast] != val) {
                nums[slow++] = nums[fast];
            }
        }
        return slow;
    }
};

// directional pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            while(left <= right && nums[left] != val) {
                left++;
            }
            while(left <= right && nums[right] == val) {
                right--;
            }
            if(left < right) {
                nums[left] ^= nums[right];
                nums[right] ^= nums[left];
                nums[left] ^= nums[right];
                left++;
                right--;
            }
        }
        return left;
    }
};