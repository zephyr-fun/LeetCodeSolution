// 2022.04.06
class Solution {
public:
    // price[3] - preice[0] = (preice[3] - preice[2]) + (preice[2] - preice[1]) + (preice[1] - preice[0])
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for(int i = 0; i < prices.size() - 1; i++){
            if(prices[i + 1] - prices[i] > 0){
                res += prices[i + 1] - prices[i];
            }
        }
        return res;
    }
};