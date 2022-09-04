// 2022.09.04
// vector version
class Solution {
public:
    vector<int> cur;
    bool check() {
        for(int i = 0; i < 32; i++) {
            if(cur[i] > 1) {
                return false;
            }
        }
        return true;
    }
    void insert(int num) {
        for(int i = 31; i >= 0; i--) {
            cur[i] += ((num >> i) & 1);
        }
    }
    void remove(int num) {
        for(int i = 31; i >= 0; i--) {
            cur[i] -= ((num >> i) & 1);
        }
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        cur.resize(32, 0);
        int res = 1;
        while(right < n) {
            insert(nums[right]);
            right++;
            while(!check()) {
                remove(nums[left]);
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};

// bit version
class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int cur = 0;
        int left = 0;
        int right = 0;
        int res = 0;
        while(right < n) {
            while(left <= right && (nums[right] & cur) != 0) {
                cur ^= nums[left];
                left++;
            }
            cur |= nums[right];
            right++;
            res = max(res, right - left);
        }
        return res;
    }
};