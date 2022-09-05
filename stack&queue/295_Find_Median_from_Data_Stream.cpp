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

// 2022.09.05
class MedianFinder {
public:
    priority_queue<double, vector<double>, less<int>> left;
    priority_queue<double, vector<double>, greater<int>> right;
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(left.size() == right.size()) {
            if(left.size() == 0) {
                left.push(num);
            }
            else {
                if(num > right.top()) {
                    left.push(right.top());
                    right.pop();
                    right.push(num);
                }
                else {
                    left.push(num);
                }
            }
        }
        else {
            if(num < left.top()) {
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else {
                right.push(num);
            }
        }
    }
    
    double findMedian() {
        if(left.size() == right.size()) {
            return (left.top() + right.top()) / 2;
        }
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */