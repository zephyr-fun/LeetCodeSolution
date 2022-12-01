// 2022.12.01
// set
// AVL Adelson-Velsky and Landis Tree
// Red Black Tree
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> set;
        for(int i = 0; i < nums.size(); i++) {
            auto lb = set.lower_bound((long)nums[i] - t);
            if(lb != set.end() && *lb <= (long)nums[i] + t) {
                return true;
            }
            set.insert(nums[i]);
            if(i >= k) {
                set.erase(nums[i - k]);
            }
        }
        return false;
    }
};