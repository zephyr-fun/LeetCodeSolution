// 2022.08.27
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        int n = a.size();
        vector<int> res(n);
        if(n == 0) {
            return res;
        }
        vector<int> left(n);
        vector<int> right(n);
        left[0] = 1;
        right[n - 1] = 1;
        for(int i = 1; i < n; i++) {
            left[i] = left[i - 1] * a[i - 1];
        }
        for(int i = n - 2; i >= 0; i--) {
            right[i] = right[i + 1] * a[i + 1];
        }
        for(int i = 0; i < n; i++) {
            res[i] = left[i] * right[i];
        }
        return res;
    }
};