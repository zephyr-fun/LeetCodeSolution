// 2022.04.07
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int res = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            }
            if(prices[i] > minPrice + fee){
                res += prices[i] - minPrice - fee; // -fee
                minPrice = prices[i] - fee; // -fee
            }
        }
        return res;
    }
};