// 2022.06.26
// pair<int, int> store segment
class MyCalendar {
public:
    set<pair<int, int>> set;
    const int INF = 2e9;
    MyCalendar() {
        set.insert({-INF, -INF});
        set.insert({INF, INF});
    }
    
    bool check(pair<int, int> a, pair<int, int> b) {
        if(a.second <= b.first || b.second <= a.first) {
            return false;
        }
        return true;
    }

    bool book(int start, int end) {
        auto i = set.lower_bound({start, INF}); // first number less or equal to {key}
        auto j = i;
        j--;
        pair<int, int> t(start, end);
        if(check(*i, t) || check(*j, t)) {
            return false;
        }
        set.insert(t);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

// 2022.06.30
class MyCalendar {
public:
    set<pair<int, int>> set;
    const int INF = 2e9;
    MyCalendar() {
        set.insert({INF, INF});
        set.insert({-INF, -INF});
    }
    
    bool check(pair<int, int> a, pair<int, int> b) {
        if(a.second <= b.first || a.first >= b.second) {
            return false;
        }
        return true;
    }

    bool book(int start, int end) {
        auto i = set.lower_bound({start, end});
        auto j = i;
        j--;
        pair<int, int> t(start, end);
        if(check(*i, t) || check(*j, t)) {
            return false;
        }
        set.insert(t);
        return true;
    }
};