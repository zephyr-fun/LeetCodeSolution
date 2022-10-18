// 2022.05.19
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> nums;
        while(n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        int lenN = nums.size();
        vector<int> digit;
        for(int i = 0; i < digits.size(); i++) {
            digit.push_back(digits[i][0] - '0'); // string
        }
        int lenD = digit.size();

        // diff len 
        int res = 0;
        for(int i = 1; i < lenN; i++) {
            res += pow(lenD, i);
        }

        // same len
        for(int i = lenN - 1; i >= 0; i--) {
            int left = 0;
            int right = lenD - 1;
            int pos = 0;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(digit[mid] <= nums[i]) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(digit[pos] > nums[i]) {
                break;
            }
            else if(digit[pos] == nums[i]) {
                res += pos * pow(lenD, i);
                if(i == 0) {
                    res++;
                }
            }
            else {
                res += (pos + 1) * pow(lenD, i);
                break;
            }
        }
        return res;
    }
};

// 2022.05.27
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> nums;
        while(n != 0) {
            nums.push_back(n % 10);
            n /= 10;
        }
        int lenN = nums.size();
        vector<int> digit;
        for(int i = 0; i < digits.size(); i++) {
            digit.push_back(stoi(digits[i]));
        }
        int lenD = digit.size();
        int res = 0;

        // diff len, less than
        for(int i = 1; i < lenN; i++) {
            res += pow(lenD, i);
        }

        // same len
        for(int i = lenN - 1; i >= 0; i--) {
            int left = 0;
            int right = lenD - 1;
            int pos = 0;
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if(digit[mid] <= nums[i]) {
                    pos = mid;
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            if(digit[pos] > nums[i]) {
                break;
            }
            else if(digit[pos] == nums[i]) {
                res += pos * pow(lenD, i);
                if(i == 0) {
                    res++;
                }
            }
            else {
                res += (pos + 1) * pow(lenD, i);
                break;
            }
        }
        return res;
    }
};

// 2022.10.18
// https://leetcode.cn/problems/numbers-at-most-n-given-digit-set/solution/shu-wei-dp-tong-yong-mo-ban-xiang-xi-zhu-e5dg/
class Solution {
public:
    vector<int> dp;
    vector<string> digits;
    int m;
    string s;
    int dfs(int i, bool is_limit, bool is_num) {
        if(i == m) {
            return is_num;
        }
        if(!is_limit && is_num && dp[i] >= 0) {
            return dp[i];
        }
        int res = 0;
        if(!is_num) {
            res = dfs(i + 1, false, false);
        }
        char up = is_limit ? s[i] : '9';
        for(auto& d : digits) {
            if(d[0] > up) {
                break;
            }
            res += dfs(i + 1, is_limit && d[0] == up, true);
        }
        if(!is_limit && is_num) {
            dp[i] = res;
        }
        return res;
    }
    int atMostNGivenDigitSet(vector<string> &digits_, int n) {
        s = to_string(n);
        m = s.length();
        dp.resize(m, -1);
        digits = digits_;
        return dfs(0, true, false);
    }
};