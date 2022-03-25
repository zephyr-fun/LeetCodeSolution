// 2022.03.25
// can not maintain the original order
// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
//         int leftIndex = 0;
//         int rihgtIndex = nums.size() - 1;
//         while(leftIndex <= rihgtIndex){
//             while(leftIndex <= rihgtIndex && nums[leftIndex] != 0){
//                 leftIndex++;
//             }
//             while(leftIndex <= rihgtIndex && nums[rihgtIndex] == 0){
//                 rihgtIndex--;
//             }
//             if(leftIndex < rihgtIndex){
//                 int temp = nums[leftIndex];
//                 nums[leftIndex] = nums[rihgtIndex];
//                 nums[rihgtIndex] = temp;
//                 leftIndex++;
//                 rihgtIndex--;
//             }
//         }
//     }
// };
//
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        // remove 0, record non-zero values
        for(fast = 0; fast <nums.size(); fast++){
            if(nums[fast] != 0){
                nums[slow++] = nums[fast];
            }
        }
        // recover 0
        for(int i = slow; i < nums.size(); i++){
            nums[i] = 0;
        }
    }
};