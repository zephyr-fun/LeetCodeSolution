// 2022.09.25
// no need for monotonic stack
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> left(n, 1);
        vector<int> right(n, 1);
        left[n - 1] = 0;
        right[0] = 0;
        stack<int> lst;
        stack<int> rst;
        for(int i = 0; i < n; i++) {
            if(!lst.empty() && nums[i] < nums[lst.top()]) {
                int temp = lst.top();
                lst.pop();
                while(!lst.empty()) {
                    left[lst.top()] = i - lst.top() - 1;
                    lst.pop();
                }
                lst.push(temp);
            }
            lst.push(i);
        }
        int idx = 0;
        while(!lst.empty()) {
            left[lst.top()] = idx;
            lst.pop();
            idx++;
        }
        for(int i = n - 1; i >= 0; i--) {
            if(!rst.empty() && nums[i] < nums[rst.top()]) {
                int temp = rst.top();
                rst.pop();
                while(!rst.empty()) {
                    right[rst.top()] = rst.top() - i - 1;
                    rst.pop();
                }
                rst.push(temp);
            }
            rst.push(i);
        }
        idx = 0;
        while(!rst.empty()) {
            right[rst.top()] = idx;
            rst.pop();
            idx++;
        }
        vector<int> res;
        for(int i = k; i < n - k; i++) {
            if(left[i] >= k && right[i] >= k) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};

// simple version
class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> f(n);
        vector<int> g(n);
        f[0] = 1;
        g[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] <= nums[i - 1]) {
                f[i] = f[i - 1] + 1;
            }
            else {
                f[i] = 1;
            }
        }
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= nums[i + 1]) {
                g[i] = g[i + 1] + 1;
            }
            else {
                g[i] = 1;
            }
        }
        vector<int> res;
        for(int i = k; i < n - k; i++) {
            if(f[i - 1] >= k && g[i + 1] >= k) {
                res.emplace_back(i);
            }
        }
        return res;
    }
};