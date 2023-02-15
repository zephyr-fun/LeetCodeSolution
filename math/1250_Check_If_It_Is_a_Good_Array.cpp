// 2023.02.15
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    bool isGoodArray(vector<int>& nums) {
        int cur = 0;
        for(auto& num : nums) {
            cur = gcd(cur, num);
        }
        return cur == 1;
    }
};