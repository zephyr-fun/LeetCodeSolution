// 2022.07.01
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int maxVal = -0x3f3f3f3f;
        for(auto num : nums) {
            maxVal = max(maxVal, num);
        }
        vector<int> g(maxVal + 1);
        for(auto num : nums) {
            for(int y = 1; y * y <= num; y++) {
                if(num % y == 0) {
                    if(!g[y]) {
                        g[y] = num;
                    }
                    else {
                        g[y] = gcd(g[y], num);
                    }
                    if(y * y != num) {
                        int z = num / y;
                        if(!g[z]) {
                            g[z] = num;
                        }
                        else {
                            g[z] = gcd(g[z], num);
                        }
                    }
                }
            }
        }
        int res = 0;
        for(int i = 1; i <= maxVal; i++) {
            if(g[i] == i) {
                res++;
            }
        }
        return res;
    }
};

// 2023.01.14
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int res = 0;
        int mx = *max_element(nums.begin(), nums.end());
        bool has[mx + 1];
        memset(has, 0, sizeof(has));
        for(auto& num : nums) {
            has[num] = true;
        }
        for(int i = 1; i <= mx; i++) {
            int g = 0;
            for(int j = i; j <= mx && g != i; j += i) {
                if(has[j]) {
                    g = gcd(g, j);
                }
            }
            if(g == i) {
                res++;
            }
        }
        return res;
    }
};

// https://leetcode.cn/problems/number-of-different-subsequences-gcds/solution/ji-bai-100mei-ju-gcdxun-huan-you-hua-pyt-get7/
// optim
class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int res = 0;
        int mx = *max_element(nums.begin(), nums.end());
        bool has[mx + 1];
        memset(has, 0, sizeof(has));
        for(auto& num : nums) {
            if(!has[num]) {
                has[num] = true;
                res++;
            }
        }
        for(int i = 1; i <= mx / 3; i++) {
            if(has[i]) {
                continue;
            }
            int g = 0;
            for(int j = 2 * i; j <= mx && g != i; j += i) {
                if(has[j]) {
                    g = gcd(g, j);
                }
            }
            if(g == i) {
                res++;
            }
        }
        return res;
    }
};