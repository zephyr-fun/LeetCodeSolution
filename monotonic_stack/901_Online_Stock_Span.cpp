// 2022.10.21
// O(n * n)
// class StockSpanner {
// public:
//     vector<int> nums;
//     StockSpanner() {

//     }
    
//     int next(int price) {
//         nums.emplace_back(price);
//         stack<int> st;
//         int n = nums.size();
//         for(int i = n - 1; i >= 0; i--) {
//             while(!st.empty() && nums[i] > nums[st.top()]) {
//                 if(st.top() == n - 1) {
//                     return n - 1 - i;
//                 }
//                 st.pop();
//             }
//             st.push(i);
//         }
//         return n;
//     }
// };
// 按最大值切块
class StockSpanner {
public:
    stack<pair<int, int>> st;
    StockSpanner() {

    }
    
    int next(int price) {
        int res = 1;
        while(!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, res));
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */