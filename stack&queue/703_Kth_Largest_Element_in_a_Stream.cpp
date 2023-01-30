// 2023.01.30
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pque;
    int k;
    KthLargest(int k_, vector<int>& nums) {
        k = k_;
        for(auto& num : nums) {
            pque.push(num);
        }
        while(pque.size() > k) {
            pque.pop();
        }
    }
    
    int add(int val) {
        pque.push(val);
        while(pque.size() > k) {
            pque.pop();
        }
        return pque.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */