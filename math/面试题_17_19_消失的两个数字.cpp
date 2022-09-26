// 2022.09.26
// with sum = a + b, sqsum = a * a + b * b;
typedef long long LL;
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n = nums.size() + 2;
        LL sum = 0;
        LL sqsum = 0;
        for(int i = 1; i <= n; i++) {
            sum += i;
            sqsum += i * i;
        }
        for(auto& num : nums) {
            sum -= num;
            sqsum -= num * num;
        }
        int a_1 = (sum + sqrt(2 * sqsum - sum * sum)) / 2;
        int a_2 = (sum - sqrt(2 * sqsum - sum * sum)) / 2;
        int a;
        if(a_1 >= 1 && a_1 <= n) {
            a = a_1;
        }
        else {
            a = a_2;
        }
        int b = sum - a;
        return {a, b};
    }
};

// xor
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int xorsum = 0;
        int n = nums.size() + 2;
        // xorsum = a ^ b
        for(auto& num : nums) {
            xorsum ^= num;
        }
        for(int i = 1; i <= n; i++) {
            xorsum ^= i;
        }
        // classify functions as the lowbit func
        int classify = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int class1 = 0;
        int class2 = 0;
        for(auto& num : nums) {
            if(num & classify) {
                class1 ^= num;
            }
            else {
                class2 ^= num;
            }
        }
        for(int i = 1; i <= n; i++) {
            if(i & classify) {
                class1 ^= i;
            }
            else {
                class2 ^= i;
            }
        }
        return {class1, class2};
    }
};