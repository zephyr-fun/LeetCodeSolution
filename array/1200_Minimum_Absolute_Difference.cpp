// 2022.07.04
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return ;
        }
        int i = l;
        int j = r;
        int x = nums[(l + r) >> 1];
        while(i < j) {
            while(nums[i] < x) {
                i++;
            }
            while(nums[j] > x) {
                j--;
            }
            if(i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if(i == j && nums[j] > x) {
            j--;
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = 0x3f3f3f3f;
        int n = arr.size();
        quick_sort(arr, 0, n - 1);
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++) {
            int temp = abs(arr[i + 1] - arr[i]);
            vector<int> cur;
            cur.emplace_back(arr[i]);
            cur.emplace_back(arr[i + 1]);
            if(temp < minDiff) {
                res.clear();
                res.emplace_back(cur);
                minDiff = temp;
            }
            else if(temp == minDiff) {
                res.emplace_back(cur);
            }
        }
        return res;
    }
};

// initializer_list
class Solution {
public:
    void quick_sort(vector<int>& nums, int l, int r) {
        if(l >= r) {
            return ;
        }
        int i = l;
        int j = r;
        int x = nums[(l + r) >> 1];
        while(i < j) {
            while(nums[i] < x) {
                i++;
            }
            while(nums[j] > x) {
                j--;
            }
            if(i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        if(i == j && nums[j] > x) {
            j--;
        }
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDiff = 0x3f3f3f3f;
        int n = arr.size();
        quick_sort(arr, 0, n - 1);
        vector<vector<int>> res;
        for(int i = 0; i < n - 1; i++) {
            int temp = abs(arr[i + 1] - arr[i]);
            if(temp < minDiff) {
                res = {{arr[i], arr[i + 1]}};
                minDiff = temp;
            }
            else if(temp == minDiff) {
                res.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};