// 2022.06.17
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0) {
                zeros++;
            }
        }
        int m = n + zeros;
        arr.resize(m, 0);
        int oldIdx = n - 1;
        int newIdx = m - 1;
        while(oldIdx >= 0) {
            if(arr[oldIdx] == 0) {
                arr[newIdx] = 0;
                newIdx--;
                arr[newIdx] = 0;
            }
            else {
                arr[newIdx] = arr[oldIdx];
            }
            newIdx--;
            oldIdx--;
        }
        arr.resize(n);
    }
};