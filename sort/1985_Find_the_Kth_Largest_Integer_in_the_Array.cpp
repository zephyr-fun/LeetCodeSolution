// 2022.07.09
// you have to avoid nums[i] length within 100
class Solution {
public:
    int quick_sel(vector<int>& nums, int l, int r, int k) {
        if(l == r) {
            return nums[l];
        }
        int x = nums[(l + r) >> 1];
        int i = l - 1;
        int j = r + 1;
        while(i < j) {
            while(nums[++i] > x);
            while(nums[--j] < x);
            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }
        int sl = j - l + 1;
        if(k <= sl) {
            return quick_sel(nums, l, j, k);
        }
        return quick_sel(nums, j + 1, r, k - sl);
    } 
    string kthLargestNumber(vector<string>& strs, int k) {
        int n = strs.size();
        vector<int> nums;
        for(auto iter : strs) {
            nums.emplace_back(stoi(iter));
        }
        int res = quick_sel(nums, 0, n - 1, k);
        return to_string(res);
    }
};

// optim
// nth_element in algorithm
class Solution {
public:
    static bool cmp(string a, string b) {
        return a.size() != b.size() ? a.size() > b.size() : a > b;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + k - 1, nums.end(), cmp);
        return nums[k - 1];
    }
};