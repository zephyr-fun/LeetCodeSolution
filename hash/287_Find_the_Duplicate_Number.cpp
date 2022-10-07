// 2022.10.07
// with next
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cur = nums[0];
        int n = nums.size();
        while(cur < n) {
            int next = cur;
            if(nums[next] < 0) {
                return next;
            }
            cur = nums[next];
            nums[next] *= -1;
        }
        return 0;
    }
};

// without next
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int cur = nums[0];
        int n = nums.size();
        while(cur < n) {
            if(nums[cur] < 0) {
                return cur;
            }
            nums[cur] *= -1;
            cur = nums[cur] * -1;
        }
        return 0;
    }
};