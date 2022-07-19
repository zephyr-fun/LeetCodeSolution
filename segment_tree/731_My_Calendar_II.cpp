// 2022.06.26
// diff array + map inplementation(deal with 1e9)
class MyCalendarTwo {
public:
    map<int, int> map;
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int sum = 0;
        for(auto [k, v] : map) {
            sum += v;
            if(sum >= 3) {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */

// 2022.06.30
class MyCalendarTwo {
public:
    map<int, int> map;
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int cur = 0;
        for(auto [k, v] : map) {
            cur += v;
            if(cur >= 3) {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
    }
};

// 2022.07.19
class MyCalendarTwo {
public:
    map<int, int> map;
    MyCalendarTwo() {

    }
    
    bool book(int start, int end) {
        map[start]++;
        map[end]--;
        int cur = 0;
        for(auto [k, v] : map) {
            cur += v;
            if(cur >= 3) {
                map[start]--;
                map[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */