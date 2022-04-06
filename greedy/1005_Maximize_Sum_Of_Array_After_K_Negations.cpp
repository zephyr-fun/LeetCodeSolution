// 2022.04.06
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int index = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0){
                index++;
            }
            else{
                break;
            }
        }
        if(index >= k){
            for(int i = 0; i < k; i++){
                nums[i] = -nums[i];
            }
        }
        else{
            for(int i = 0; i < index; i++){
                nums[i] = -nums[i];
            }
            sort(nums.begin(), nums.end());
            nums[0] = (k - index) % 2 == 0 ? nums[0] : -nums[0];
        }
        for(int i = 0; i < nums.size(); i++){
            res += nums[i];
        }
        return res;
    }
};

// spacial cmp
class Solution {
static bool cmp(int a, int b){
    return abs(a) > abs(b);
}
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0 && k > 0){
                nums[i] *= -1;
                k--;
            }
        }
        if(k % 2 == 1){
            nums[nums.size() - 1] *= -1;
        }
        int res = 0;
        for(auto num : nums){
            res += num;
        }
        return res;
    }
};