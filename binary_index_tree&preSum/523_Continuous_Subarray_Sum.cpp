// 2022.05.16
// LTE
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        vector<int> prefix(nums.size() + 1, 0);
        for(int i = 1; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        for(int i = 1; i <= nums.size(); i++) {
            for(int j = i + 1; j <= nums.size(); j++) {
                if((prefix[j] - prefix[i - 1]) % k == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

// hash set + prefix

// 为啥前缀和+同余定理有用呢？
// 以pre[i]与pre[j](i < j)为例
// pre[i] = nums[0] + nums[1] + nums[2] + ... + nums[i]
// pre[j] = nums[0] + nums[1] + nums[2] + ... + nums[i] + nums[i+1] + ... + nums[j]
// （注意下面的k就是题中给的k）
// 设：rem_i = pre[i] % k 可化为 pre[i] = x * k + rem_i  (x = pre[i] / k)(向下取整)
// 设：rem_j = pre[j] % k 可化为 pre[j] = y * k + rem+j  (y = pre[j] / k)(向下取整)
// 这时候如果rem_i == rem_j（也就是pre[i]除以k与pre[j]除以k的余数相同）
// pre[j] - pre[i] = y * k + rem_j - x * k - rem_i (注意这里因为i<j，又题目中给出数字>=0，所以pre[j] - pre[i] >= 0)
//                 = (y - x) * k
// 因为(y - x)是个整数，所以如果我们找到了前缀和pre[i]与pre[j]除以k的余数相同，那么我们就找到了一个可以整除k的方案
// 但要注意这里的j - i需要>=2才行
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> set;
        vector<int> prefix(nums.size() + 1, 0);
        prefix[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            set.insert(prefix[i - 2] % k); // limit len at least greater than 2
            if(set.count(prefix[i] % k)) {
                return true;
            }
        }
        return false;
    }
};

// 2022.05.31
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> set;
        vector<int> prefix(nums.size() + 1, 0);
        prefix[1] = nums[0];
        for(int i = 2; i <= nums.size(); i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
            set.insert(prefix[i - 2] % k);
            if(set.count(prefix[i] % k)) {
                return true;
            }
        }
        return false;
    }
};