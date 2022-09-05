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