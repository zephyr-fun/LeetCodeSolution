// 2022.06.25
class Solution {
public:
    bool check(vector<int>& nums, vector<int>& group, int idx) {
        int cnt = 0;
        if(nums.size() - idx < group.size()) {
            return false;
        }
        for(auto gp : group) {
            if(gp != nums[idx]) {
                return false;
            }
            idx++;
            cnt++;
        }
        return cnt == group.size();
    }
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int n = groups.size();
        int m = nums.size();
        int cnt = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < m) {
            // cout << i << j;
            if(check(nums, groups[i], j)) {
                // cout << "if" << endl;
                j += groups[i].size(); // the update order of i and j matters
                i++;
                cnt++;
                // cout << i << j << endl;
            }
            else {
                // cout << "else" << endl;
                j++;
                // cout << i << j << endl;
            }
        }
        return cnt == n;
    }
};