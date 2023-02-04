// 2023.02.04
// 排序
// 假设已经构造出0 -> m
// 当前迭代到coins[i]，如果coins[i] > m + 1的话，无论如何取，都将大于m + 1，造成不连续
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int m = 0;
        for(auto& c : coins) {
            if(c > m + 1) {
                break;
            }
            m += c;
        }
        return m + 1;
    }
};