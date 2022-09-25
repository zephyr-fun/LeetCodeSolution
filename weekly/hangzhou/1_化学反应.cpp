// 2022.09.25
// https://leetcode.cn/contest/hhrc2022/problems/o0Ma2v/
class Solution {
public:
    int lastMaterial(vector<int>& material) {
        priority_queue<int> pque;
        for(auto& m : material) {
            pque.push(m);
        }
        while(pque.size() > 1) {
            int a = pque.top();
            pque.pop();
            int b = pque.top();
            pque.pop();
            if(a != b) {
                pque.push(abs(a - b));
            }
        }
        return pque.empty() ? 0 : pque.top();
    }
};