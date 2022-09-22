// 2022.09.15
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stl;
        stack<int> str;
        for(int i = 0; i < n; i++) {
            while(!str.empty() && arr[str.top()] >= arr[i]) {
                right[str.top()] = i;
                str.pop();
            }
            str.push(i);
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!stl.empty() && arr[stl.top()] > arr[i]) {
                left[stl.top()] = i;
                // cout << stl.top() << left[stl.top()] << i << endl;
                stl.pop();
            }
            stl.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            int temp = ((long long)(right[i] - i) * (long long)(i - left[i]) % mod) * arr[i] % mod;
            // int temp = (right[i] - left[i] - 1) * arr[i];
            // cout << "r:" << right[i] << "l:" << left[i] << 'a' << arr[i] << endl;
            res = (res + temp) % mod;
        }
        return res;
    }
};

// 2022.09.22
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> ls;
        stack<int> rs;
        for(int i = 0; i < n; i++) {
            while(!rs.empty() && arr[rs.top()] >= arr[i]) {
                right[rs.top()] = i;
                rs.pop();
            }
            rs.push(i);
        }
        for(int i = n - 1; i >= 0; i--) {
            while(!ls.empty() && arr[ls.top()] > arr[i]) {
                left[ls.top()] = i;
                ls.pop();
            }
            ls.push(i);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            // cout << left[i] << right[i] << arr[i] << endl;
            long long temp = (long long)(i - right[i]) * (long long)(left[i] - i) * (long long)arr[i];
            res = (temp + res) % mod;
        }
        return res;
    }
};