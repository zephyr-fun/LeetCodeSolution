// 2022.09.03
class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>>& temp = map[key];
        int n = temp.size();
        int left = 0;
        int right = n - 1;
        int pos = -1;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(temp[mid].first <= timestamp) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if(pos == -1) {
            return "";
        }
        return temp[pos].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// 2022.09.27
class TimeMap {
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key].emplace_back(make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        auto& temp = map[key];
        int left = 0;
        int right = temp.size() - 1;
        int pos = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(temp[mid].first <= timestamp) {
                pos = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        if(pos == -1) {
            return "";
        }
        return temp[pos].second;
    }

private:
    unordered_map<string, vector<pair<int, string>>> map;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */