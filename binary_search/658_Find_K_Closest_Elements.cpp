// 2022.08.25
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        int pos = 0; // notice
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(arr[mid] > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
                pos = mid;
            }
        }
        pos = pos + 1 < n && abs(arr[pos] - x) > abs(arr[pos + 1] - x) ? pos + 1 : pos;
        left = pos;
        right = pos;
        vector<int> res(k);
        k--;
        while(k--) {
            int leftVal = 0x3f3f3f3f;
            int rightVal = 0x3f3f3f3f;
            if(left - 1 >= 0) {
                leftVal = arr[left - 1];
            }
            if(right + 1 < n) {
                rightVal = arr[right + 1];
            }
            if(abs(leftVal - x) <= abs(rightVal - x)) {
                left--;
            }
            else {
                right++;
            }
        }
        for(int i = 0; i < right - left + 1; i++) { // notice
            res[i] = arr[i + left];
        }
        return res;
    }
};