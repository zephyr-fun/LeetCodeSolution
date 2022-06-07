// 2022.06.07
// binary search
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int> res(m, 0);
        vector<int> sum(n + 1, 0);
        vector<int> canle;
        for(int i = 0; i < n; i++) {
            if(s[i] == '|') {
                canle.emplace_back(i);
                sum[i + 1] = sum[i];
            }
            else {
                sum[i + 1] = sum[i] + 1;
            }
        }
        if(canle.size() == 0) {
            return res;
        }
        for(int i = 0; i < m; i++) {
            int leftQuery = queries[i][0];
            int rightQuery = queries[i][1];
            int leftBound = -1;
            int rightBound = -1;
            int left = 0;
            int right = canle.size() - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(canle[mid] >= leftQuery) {
                    leftBound = canle[mid];
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            if(leftBound == -1 || leftBound > rightQuery) {
                continue;
            }
            left = 0;
            right = canle.size() - 1;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(canle[mid] <= rightQuery) {
                    rightBound = canle[mid];
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(rightBound == -1 || rightBound < leftQuery) {
                continue;
            }
            res[i] = sum[rightBound + 1] - sum[leftBound];
        }
        return res;
    }
};

// monotonic like
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        vector<int> sum(n + 1, 0);
        vector<int> res(m, 0);
        for(int i = 0, j = n - 1, p = -1, q = -1; i < n; i++, j--) {
            if(s[i] == '|') {
                p = i;
            }
            if(s[j] == '|') {
                q = j;
            }
            left[i] = p;
            right[j] = q;
            sum[i + 1] = sum[i] + (s[i] == '*' ? 1 : 0);
        }
        for(int i = 0; i < m; i++) {
            int leftQuery = queries[i][0];
            int rightQuery = queries[i][1];
            int leftBound = right[leftQuery];
            int rightBound = left[rightQuery];
            if(leftBound != -1 && leftBound <= rightBound) {
                res[i] = sum[rightBound + 1] - sum[leftBound];
            }
        }
        return res;
    }
};