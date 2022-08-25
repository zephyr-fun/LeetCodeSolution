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