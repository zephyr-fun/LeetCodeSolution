// 2022.06.28
// bucket_sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int tot = 2e4;
        int bucket[tot];
        int mod = 1e4;
        memset(bucket, 0, sizeof(bucket));
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            bucket[nums[i] + mod]++;
        }
        int idx = 2*1e4 - 1;
        while(1) {
            while(bucket[idx] != 0) {
                bucket[idx]--;
                k--;
                if(k == 0) {
                    return idx - mod;
                }
            }
            idx--;
        }
        return -1;
    }
};

// 2022.07.09
// quick_select
class Solution {
public:
    int n;
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
    int findKthLargest(vector<int>& nums, int k) {
        n = nums.size();
        return quick_sel(nums, 0, n - 1, k);
    }
};

// 2022.10.10
class Solution {
public:
    int quick_select(vector<int>& nums, int l, int r, int k) {
        if(l == r) {
            return nums[l];
        }
        int x = nums[(l + r) >> 1];
        int i = l - 1;
        int j = r + 1;
        while(i < j) {
            // from big to small
            while(nums[++i] > x);
            while(nums[--j] < x);
            if(i < j) {
                swap(nums[i], nums[j]);
            }
        }
        int sl = j - l + 1;
        if(k <= sl) {
            return quick_select(nums, l, j, k);
        }
        return quick_select(nums, j + 1, r, k - sl);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quick_select(nums, 0, nums.size() - 1, k);
    }
};

// 2022.10.22
class Solution {
public:
    int quick_select(vector<int>& nums, int l, int r, int k) {
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
            return quick_select(nums, l, j, k);
        }
        return quick_select(nums, j + 1, r, k - sl);
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quick_select(nums, 0, n - 1, k);
    }
};

// quick_select