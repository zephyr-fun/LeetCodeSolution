// 2023.01.02
class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // pair<int,int> -> (price, amount)
        priority_queue<pair<int,int>> buy;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> sell;
        for(const auto& order : orders) {
            int p = order[0];
            int a = order[1];
            int t = order[2];
            if(t == 0) { // buy, find sell
                while(a > 0 && sell.size() && sell.top().first <= p) {
                    auto [price, amount] = sell.top();
                    sell.pop();
                    int cnt = min(amount, a);
                    amount -= cnt;
                    a -= cnt;
                    if(amount > 0) {
                       sell.push({price, amount});
                    }
                }
                if(a > 0) {
                    buy.push({p, a});
                }
            } 
            else { // sell, find buy
                while(a > 0 && buy.size() && buy.top().first >= p) {
                    auto [price, amount] = buy.top();
                    buy.pop();
                    int cnt = min(amount, a);
                    amount -= cnt;
                    a -= cnt;
                    if(amount > 0) {
                        buy.push({price, amount});
                    }
                }
                if(a > 0) {
                    sell.push( {p, a} );
                }
            } 
        }
        int ans = 0;
        while(buy.size()) {
            ans += buy.top().second;
            buy.pop();
            ans %= int(1e9 + 7);
        }
        while(sell.size()) {
            ans += sell.top().second;
            sell.pop();
            ans %= int(1e9 + 7);
        } 
        return ans;
    }
};