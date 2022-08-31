// 2022.08.25
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double, vector<double>, less<double>> leftHalf;
    priority_queue<double, vector<double>, greater<double>> rightHalf;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(leftHalf.size() == rightHalf.size()) {
            if(rightHalf.size() == 0) {
                leftHalf.push(num);
            }
            else {
                if(num > rightHalf.top()) {
                    leftHalf.push(rightHalf.top());
                    rightHalf.pop();
                    rightHalf.push(num);
                }
                else {
                    leftHalf.push(num);
                }
            }
        }
        else {
            if(num < leftHalf.top()) {
                rightHalf.push(leftHalf.top());
                leftHalf.pop();
                leftHalf.push(num);
            }
            else {
                rightHalf.push(num);
            }
        }
    }
    
    double findMedian() {
        if(leftHalf.size() == rightHalf.size()) {
            return (leftHalf.top() + rightHalf.top()) / 2;
        }
        else {
            return leftHalf.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 2022.08.31
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<double, vector<double>, less<double>> left_half;
    priority_queue<double, vector<double>, greater<double>> right_half;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left_half.size() == right_half.size()) {
            if(left_half.size() == 0) { // note nullptr
                left_half.push(num);
            }
            else {
                if(num > right_half.top()) {
                    left_half.push(right_half.top());
                    right_half.pop();
                    right_half.push(num);
                }
                else {
                    left_half.push(num);
                }
            }
        }
        else {
            if(num < left_half.top()) {
                right_half.push(left_half.top());
                left_half.pop();
                left_half.push(num);
            }
            else {
                right_half.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left_half.size() == right_half.size()) {
            return (left_half.top() + right_half.top()) / 2;
        }
        return left_half.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */