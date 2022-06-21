// 2022.06.06
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();
        for(int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        while(k >= sum) {
            k -= sum;
        }
        for(int i = 0; i < n; i++) {
            if(chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};

//
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int count = 0;
        while(k >= 0) {
            k -= chalk[count % n];
            count++;
        }
        return (count - 1) % n;
    }
};

// 2022.06.21
// mod + binary search
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<long long> sum(n, 0);
        sum[0] = chalk[0];
        for(int i = 1; i < n; i++) {
            sum[i] = sum[i - 1] + chalk[i];
        }
        k = k % sum[n - 1];
        int left = 0;
        int right = n - 1;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(sum[mid] > k) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};