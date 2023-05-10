// 2022.09.05
class StockPrice {
public:
    unordered_map<int, int> map;
    multiset<int> mset;
    int cur;
    StockPrice() {
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        cur = max(cur, timestamp);
        if(map.count(timestamp)) {
            int old = map[timestamp];
            auto pos = mset.find(old);
            mset.erase(pos);
        }
        map[timestamp] = price;
        mset.insert(price);
    }
    
    int current() {
        return map[cur];
    }
    
    int maximum() {
        return *mset.rbegin();
    }
    
    int minimum() {
        return *mset.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

// 2022.09.20
class StockPrice {
public:
    unordered_map<int, int> map;
    multiset<int> set;
    int cur;
    StockPrice() {
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        cur = max(cur, timestamp);
        if(map.count(timestamp)) {
            int old = map[timestamp];
            auto pos = set.find(old);
            set.erase(pos);
        }
        map[timestamp] = price;
        set.insert(price);
    }
    
    int current() {
        return map[cur];
    }
    
    int maximum() {
        return *set.rbegin();
    }
    
    int minimum() {
        return *set.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */

// 2023.05.09
class StockPrice {
public:
    unordered_map<int, int> map;
    multiset<int> prices;
    int cur;

    StockPrice() {
        cur = 0;
    }
    
    void update(int timestamp, int price) {
        if(map.count(timestamp)) {
            auto pos = prices.find(map[timestamp]); // erase function of multiset takes either iterator or value as parameter
            prices.erase(pos);
        }
        if(timestamp > cur) {
            cur = timestamp;
        }
        map[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return map[cur];
    }
    
    int maximum() {
        return *prices.rbegin();
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */