// 2022.06.17
// plain solution
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

// simulate stack
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int top = 0; // refers to the top of a stack
        int i = -1; // refers to current arr index
        int n = arr.size();
        while(top < n) {
            i++;
            if(arr[i] == 0) {
                top += 2;
            }
            else {
                top++;
            }
        }
        int j = n - 1;
        if(top == n + 1) {
            arr[j] = 0;
            i--;
            j--;
        }
        while(i >= 0) {
            arr[j] = arr[i];
            j--;
            if(arr[i] == 0) {
                arr[j] = arr[i];
                j--;
            }
            i--;
        }
    }
};