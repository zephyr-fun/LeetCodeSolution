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

// 2022.10.20
// same as 142
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        slow = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};