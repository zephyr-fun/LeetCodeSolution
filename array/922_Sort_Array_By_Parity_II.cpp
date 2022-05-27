// 2022.05.27
// non optim
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int size = nums.size();
        vector<int> odd(size / 2, 0);
        vector<int> even(size / 2, 0);
        int oddIndex = 0;
        int evenIndex = 0;
        for(int i = 0; i < size; i++) {
            if((nums[i] & 1) == 0) {
                even[evenIndex] = nums[i];
                evenIndex++;
            }
            else {
                odd[oddIndex] = nums[i];
                oddIndex++;
            }
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end());
        vector<int> res(size, 0);
        oddIndex = 0;
        evenIndex = 0;
        for(int i = 0; i < size; i++) {
            if((i & 1) == 0) {
                res[i] = even[evenIndex];
                evenIndex++;
            }
            else {
                res[i] = odd[oddIndex];
                oddIndex++;
            }
        }
        return res;
    }
};

// optim
// please read the problem carefully
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndex = 0;
        int oddIndex = 1;
        vector<int> res(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if((nums[i] & 1) == 0) {
                res[evenIndex] = nums[i];
                evenIndex += 2;
            }
            else {
                res[oddIndex] = nums[i];
                oddIndex += 2;
            }
        }
        return res;
    }
};

// optim double pointer
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int evenIndex = 0;
        int oddIndex = 1;
        while(evenIndex < nums.size()) {
            if(nums[evenIndex] & 1) {
                while(oddIndex < nums.size() && (nums[oddIndex] & 1)) {
                    oddIndex += 2;
                }
                nums[evenIndex] ^= nums[oddIndex];
                nums[oddIndex] ^= nums[evenIndex];
                nums[evenIndex] ^= nums[oddIndex];
                oddIndex += 2;
            }
            evenIndex += 2;
        }
        return nums;
    }
};