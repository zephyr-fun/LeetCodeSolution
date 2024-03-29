// 2022.05.11
class Solution {
public:
    map<vector<int>, int> memo;

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();

        // 过滤不需要计算的大礼包，只保留需要计算的大礼包
        vector<vector<int>> filterSpecial;
        for (auto & sp : special) {
            int totalCount = 0, totalPrice = 0;
            for (int i = 0; i < n; ++i) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if (totalCount > 0 && totalPrice > sp[n]) {
                filterSpecial.emplace_back(sp);
            }
        }

        return dfs(price, special, needs, filterSpecial, n);
    }

    // 记忆化搜索计算满足购物清单所需花费的最低价格
    int dfs(vector<int> price,const vector<vector<int>> & special, vector<int> curNeeds, vector<vector<int>> & filterSpecial, int n) {
        if (!memo.count(curNeeds)) {
            int minPrice = 0;
            for (int i = 0; i < n; ++i) {
                minPrice += curNeeds[i] * price[i]; // 不购买任何大礼包，原价购买购物清单中的所有物品
            }
            for (auto & curSpecial : filterSpecial) {
                int specialPrice = curSpecial[n];
                vector<int> nxtNeeds;
                for (int i = 0; i < n; ++i) {
                    if (curSpecial[i] > curNeeds[i]) { // 不能购买超出购物清单指定数量的物品
                        break;
                    }
                    nxtNeeds.emplace_back(curNeeds[i] - curSpecial[i]);
                }
                if (nxtNeeds.size() == n) { // 大礼包可以购买
                    minPrice = min(minPrice, dfs(price, special, nxtNeeds, filterSpecial, n) + specialPrice);
                }
            }
            memo[curNeeds] = minPrice;
        }
        return memo[curNeeds];
    }
};

// 2022.05.11
class Solution {
public:
    map<vector<int>, int> dp;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        int n = price.size(); // total kind
        vector<vector<int>> validSpecial;
        for(auto& sp : special) {
            int totalCount = 0;
            int totalPrice = 0;
            for(int i = 0; i < n; i++) {
                totalCount += sp[i];
                totalPrice += sp[i] * price[i];
            }
            if(totalCount > 0 && totalPrice > sp[n]) {
                validSpecial.push_back(sp);
            }
        }
        return dfs(price, validSpecial, needs, n);
    }
    int dfs(vector<int>& price, vector<vector<int>>& validSpecial, vector<int> needs, int n) {
        if(!dp.count(needs)) {
            int minPrice = 0;
            // don't buy special, total cost
            for(int i = 0; i < n; i++) {
                minPrice += needs[i] * price[i];
            }
            for(auto& special : validSpecial) {
                int specialPrice = special[n];
                vector<int> nextNeeds;
                for(int i = 0; i < n; i++) {
                    if(special[i] > needs[i]) {
                        break;
                    }
                    nextNeeds.push_back(needs[i] - special[i]);
                }
                if(nextNeeds.size() == n) {
                    minPrice = min(minPrice, dfs(price, validSpecial, nextNeeds, n) + specialPrice);
                }
            }
            dp[needs] = minPrice;
        }
        return dp[needs];
    }
};

// 2022.05.20
class Solution {
public:
    vector<int> _price;
    vector<vector<int>> _special;
    int _kind; 
    map<vector<int>, int> map;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        _price = price;
        int kind = price.size();
        _kind = kind;
        for(auto bag : special) {
            int sum = 0;
            for(int i = 0; i < kind; i++) {
                sum += bag[i] * price[i];
            }
            if(sum > bag[kind]) {
                _special.push_back(bag);
            }
        }
        return dfs(needs);
    }
    int dfs(vector<int>& needs) {
        if(map.find(needs) == map.end()) {
            int minPrice = 0;
            for(int i = 0; i < _kind; i++) {
                minPrice += needs[i] * _price[i];
            }
            // cout << "minPrice" << minPrice << endl;
            for(auto bag : _special) {
                int bagVal = bag[_kind];
                // cout << "bagVal" << bagVal << endl;
                vector<int> nextNeeds;
                for(int i = 0; i < _kind; i++) {
                    if(bag[i] > needs[i]) {
                        break;
                    }
                    nextNeeds.push_back(needs[i] - bag[i]);
                }
                if(nextNeeds.size() == _kind) {
                    minPrice = min(minPrice, dfs(nextNeeds) + bagVal);
                }
            }
            map[needs] = minPrice;
        }
        return map[needs];
    }
};

// again
class Solution {
public:
    map<vector<int>, int> map;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int kind = price.size();
        vector<vector<int>> validSpecial;
        for(auto bag : special) {
            int sum = 0;
            for(int i = 0; i < kind; i++) {
                sum += price[i] * bag[i];
            }
            if(sum > bag[kind]) {
                validSpecial.push_back(bag);
            }
        }
        return dfs(price, validSpecial, needs, kind);
    }
    int dfs(vector<int>& price, vector<vector<int>>& validSpecial, vector<int>& needs, int kind) {
        if(map.find(needs) == map.end()) {
            int minPrice = 0;
            for(int i = 0; i < kind; i++) {
                minPrice += price[i] * needs[i];
            }
            for(auto bag : validSpecial) {
                vector<int> nextNeeds;
                for(int i = 0; i < kind; i++) {
                    if(bag[i] > needs[i]) {
                        break;
                    }
                    nextNeeds.push_back(needs[i] - bag[i]);
                }
                if(nextNeeds.size() == kind) {
                    minPrice = min(minPrice, dfs(price, validSpecial, nextNeeds, kind) + bag[kind]);
                }
            }
            map[needs] = minPrice;
        }
        return map[needs];
    }
};