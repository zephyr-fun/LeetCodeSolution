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

// 按最大值按区域分块，向前合并，最大值总在最右边，保证了超过即可完全合并
//                  |(60, 1)|
// |(60, 1)|        |(70, 2)|       |(75, 4)|
// |(80, 1)|        |(80, 1)|       |(80, 1)|       |(85, 6)|
// |(100, 1)|       |(100, 1)|      |(100, 1)|      |(100, 1)|
//           -> 70            -> 75           -> 85 
// 2023.09.20
class StockSpanner {
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int res = 1;
        while (!st.empty() && st.top().first <= price) {
            res += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, res));
        return res;
    }

private:
    stack<pair<int, int>> st;
};