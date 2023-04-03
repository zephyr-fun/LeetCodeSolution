// 2023.04.03
// 最终判断的主体应该是左边需要被交换的大数，而右边多个相同值中还需要找一个最接近左边的（保证尽可能大）
// class Solution {
// public:
//     vector<int> prevPermOpt1(vector<int>& arr) {
//         unordered_map<int, int> map;
//         stack<int> st;
//         int n = arr.size();
//         for(int i = n - 1; i >= 0; i--) {
//             while(!st.empty() && arr[i] > arr[st.top()]) {
//                 map[st.top()] = i;
//                 st.pop();
//             }
//             st.push(i);
//         }
//         for(int i = n - 1; i >= 0; i--) {
//             if(map.count(i)) {
//                 swap(arr[i], arr[map[i]]);
//                 break;
//             }
//         }
//         return arr;
//     }
// };

// O(n)
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] > arr[i + 1]) {
                int j = i + 1;
                while(j + 1 < n && arr[j + 1] < arr[i]) {
                    j++;
                }
                while(arr[j] == arr[j - 1]) {
                    j--;
                }
                swap(arr[i], arr[j]);
                break;
            }
        }
        return arr;
    }
};