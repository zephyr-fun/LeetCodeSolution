// 2022.06.27
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int findGCD(vector<int>& nums) {
        int minVal = 0x3f3f3f3f;
        int maxVal = -0x3f3f3f3f;
        for(int i = 0; i < nums.size(); i++) {
            minVal = min(minVal, nums[i]);
            maxVal = max(maxVal, nums[i]);
        }
        return gcd(maxVal, minVal);
    }
};

// 2022.07.01
class Solution {
public:
    int gcd(int a, int b) {
        return b ? gcd(b, a % b) : a;
    }
    int findGCD(vector<int>& nums) {
        int maxVal = -0x3f3f3f3f;
        int minVal = 0x3f3f3f3f;
        for(auto num : nums) {
            maxVal = max(maxVal, num);
            minVal = min(minVal, num);
        }
        return gcd(maxVal, minVal);
    }
};