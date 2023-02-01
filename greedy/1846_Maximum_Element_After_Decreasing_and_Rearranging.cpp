// 2023.02.01
// plain
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int res = 1;
        for(int i = 0; i < arr.size(); i++) {
            res = max(res, min(res + 1, min(arr[i], 1 + i)));
        }
        return res;
    }
};

// iteration
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] - arr[i - 1] > 1) {
                arr[i] = arr[i - 1] + 1;
            }
        }
        return arr.back();
    }
};

// O(n)
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        int cnt[n + 1];
        int limit = 0;
        memset(cnt, 0, sizeof(cnt));
        for(auto& num : arr) {
            cnt[num > n ? n : num]++;
        }
        for(int i = 1; i <= n; i++) {
            limit = limit + cnt[i] < i ? limit + cnt[i] : i;
        }
        return limit;
    }
};