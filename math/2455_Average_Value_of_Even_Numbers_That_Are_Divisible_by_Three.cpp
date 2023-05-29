// 2023.05.29
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int cnt = 0;
        int sum = 0;
        for(auto& num : nums) {
            if(num % 3 == 0 && num % 2 == 0) {
                cnt++;
                sum += num;
            }
        }
        return cnt == 0 ? 0 : sum / cnt;
    }
};