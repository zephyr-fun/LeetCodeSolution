// 2022.06.26
// TLE version
class Solution {
public:
    vector<int> prefix;
    int size;
    Solution(int n, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        int idx = 0;
        prefix.emplace_back(0);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(i == blacklist[idx]) {
                idx++;
                continue;
            }
            sum += i;
            prefix.emplace_back(sum);
        }
        size = prefix.size();
    }
    
    int pick() {
        int left = 0;
        int right = size - 1;
        int pos = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(prefix[mid] >= rand) {
                pos = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return prefix[pos] - prefix[pos - 1];
    }
};

// reverse version
// presum + binary search
// n 1e9, blacklist 1e5
// point in n && not in blacklist still more than 1e8, proess TLE
// rethink it as segments, store segments divided by blacklist
class Solution {
public:
    vector<int> preSum;
    vector<pair<int, int>> segment;
    int size;
    Solution(int n, vector<int>& blacklist) {
        sort(blacklist.begin(), blacklist.end());
        int m = blacklist.size();
        preSum.resize(m + 10, 0);
        if(m == 0) {
            segment.emplace_back(0, n - 1);
        }
        else {
            // first segment
            if(blacklist[0] != 0) {
                segment.emplace_back(0, blacklist[0] - 1);
            }
            for(int i = 1; i < m; i++) {
                if(blacklist[i - 1] == blacklist[i] - 1) {
                    continue;
                }
                segment.emplace_back(blacklist[i - 1] + 1, blacklist[i] - 1);
            }
            // last segment
            if(blacklist[m - 1] != n - 1) {
                segment.emplace_back(blacklist[m - 1] + 1, n - 1);
            }
        }
        size = segment.size();
        for(int i = 1; i <= size; i++) {
            auto seg = segment[i - 1];
            preSum[i] = preSum[i - 1] + seg.second - seg.first + 1;
        }
    }
    
    int pick() {
        int val = rand() % preSum[size] + 1;
        int idx = lower_bound(preSum.begin(), preSum.begin() + size, val) - preSum.begin();
        auto seg = segment[idx - 1];
        int a = seg.first;
        int b = seg.second;
        int end = preSum[idx];
        return b - (end - val);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */