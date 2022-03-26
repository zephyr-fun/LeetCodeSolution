// 2022.03.25
// fast slow pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); fastIndex++){
            if(val != nums[fastIndex]){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};
// Directional Pointer
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftIndex = 0;
        int rightIndex = nums.size() - 1;
        while(leftIndex <= rightIndex){
            while(leftIndex <= rightIndex && nums[leftIndex] != val){
                leftIndex++;
            }
            while(leftIndex <= rightIndex && nums[rightIndex] == val){
                rightIndex--;
            }
            if(leftIndex < rightIndex){
                nums[leftIndex++] = nums[rightIndex--];
            }
        }
        return leftIndex;
    }
};