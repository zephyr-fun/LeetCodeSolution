// 2022.06.05
// unordered_map
class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int, int> map;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            map[nums[i]] = i;
        }
        for(auto opt : operations) {
            int num = opt[0];
            int rep = opt[1];
            int pos = map[num];
            nums[pos] = rep;
            map[rep] = pos;
        }
        return nums;
    }
};

// what if there are some repeated nums, think about unionfindset
class Solution
{
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations)
    {
        int n = operations.size();
        unordered_map<int, int> map;
        for (int i = n - 1; i >= 0; i--)
        {
            int t = operations[i][1];
            if (map[t])
            {
                t = map[t];
            }
            map[operations[i][0]] = t;
        }
        int m = nums.size();
        for (int i = 0; i < m; i++)
        {
            if (map[nums[i]])
            {
                nums[i] = map[nums[i]];
            }
        }
        return nums;
    }
};