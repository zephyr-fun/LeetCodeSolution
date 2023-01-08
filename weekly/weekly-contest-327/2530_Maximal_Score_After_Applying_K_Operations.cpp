// 2023.01.08
// priority_queue
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pque;
        long long res = 0;
        for(auto& num : nums) {
            pque.push(num);
        }
        while(k) {
            int temp = pque.top();
            pque.pop();
            res += temp;
            if(temp % 3 == 0) {
                pque.push(temp / 3);
            }
            else {
                pque.push(temp / 3 + 1);
            }
            k--;
        }
        return res;
    }
};