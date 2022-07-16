// 2022.07.16
// spatial solution
class MovingAverage {
public:
    int idx = 0;
    int win = 0;
    int cnt = 0;
    vector<double> record;
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        win = size;
        record.resize(win, 0);
    }
    
    double next(int val) {
        record[idx] = val;
        idx = (idx + 1) %  win;
        cnt++;
        double sum = 0;
        for(int i = 0; i < win; i++) {
            sum += record[i];
        }
        return sum / min(cnt, win);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */

// use space optim temp
class MovingAverage {
public:
    /** Initialize your data structure here. */
    int sum = 0;
    int left = 0;
    int right = 0;
    int record[10007];
    int n = 0;
    MovingAverage(int size) {
        memset(record, 0, sizeof(record));
        n = size;
    }
    
    double next(int val) {
        record[right] = val;
        sum += val;
        right++;
        if(right - left > n) {
            sum -= record[left];
            left++;
        }
        return sum * 1.0 / (right - left);
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */