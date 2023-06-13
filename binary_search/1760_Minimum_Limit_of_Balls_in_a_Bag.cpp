// 2023.06.13
class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        // this works in nlogn
        // function<bool(int)> check = [&] (int mv) {
        //     int op = maxOperations;
        //     priority_queue<int> pque;
        //     for(auto& num : nums) {
        //         pque.push(num);
        //     }
        //     while(op && pque.top() > mv) {
        //         int cur = pque.top();
        //         pque.pop();
        //         pque.push(mv);
        //         pque.push(cur - mv);
        //         op--;
        //     }
        //     return op || pque.top() == mv;
        // };
        // this works in n
        function<bool(int)> check = [&] (int mv) {
            int res = 0;
            for(auto& num : nums) {
                res += (num - 1) / mv;
            }
            return res <= maxOperations;
        };
        int n = nums.size();
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int pos = right;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(check(mid)) {
                right = mid - 1;
                pos = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return pos;
    }
};