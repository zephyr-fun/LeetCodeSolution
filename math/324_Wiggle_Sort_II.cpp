// 2022.06.28
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int bucket[5007];
        memset(bucket, 0, sizeof(bucket));
        for(auto num : nums) {
            bucket[num]++;
        }
        int big;
        int small;
        if(n & 1){ // length is odd
            big = n - 2;
            small = n - 1;
        }
        else{ // length is even
            big= n - 1;
            small = n - 2;
        }
        int j = 5000;
        // insert big
        for(int i = 1; i <= big; i += 2){
            while(bucket[j] ==0 ) {
                j--;
            }
            nums[i] = j;
            bucket[j]--;
        }
        // insert small
        for(int i = 0; i <= small; i += 2){
            while(bucket[j] == 0) {
                j--;
            }
            nums[i] = j;
            bucket[j]--;
        }
    }
};

// 2022.12.13
// O(nlogn)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = (n / 2) - (n % 2 == 0 ? 1 : 0);
        int right = n - 1;
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                res[i] = nums[left];
                left--;
            }
            else {
                res[i] = nums[right];
                right--;
            }
        }
        nums = res;
    }
};

// optim
