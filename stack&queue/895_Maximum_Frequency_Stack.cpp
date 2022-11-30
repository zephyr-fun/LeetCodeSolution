// 2022.11.30
// https://leetcode.cn/problems/maximum-frequency-stack/solution/mei-xiang-ming-bai-yi-ge-dong-hua-miao-d-oich/
class FreqStack {
    unordered_map<int, int> cnt;
    vector<stack<int>> stacks;
public:
    FreqStack() {

    }
    
    void push(int val) {
        if(cnt[val] == stacks.size()) {
            stacks.push_back({});
        }
        stacks[cnt[val]].push(val);
        cnt[val]++;
    }
    
    int pop() {
        int val = stacks.back().top();
        stacks.back().pop();
        if(stacks.back().empty()) {
            stacks.pop_back();
        }
        cnt[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */