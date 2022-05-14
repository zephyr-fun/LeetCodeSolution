// 2022.05.14
// O(n*n*n)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res = 0;
        for(int i = 0; i < arr.size(); i ++)
            for(int sz = 1; i + sz - 1 < arr.size(); sz += 2)
                res += accumulate(arr.begin() + i, arr.begin() + i + sz, 0);
        return res;
    }
}; 
// O(n*n)
// prefix
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix = {0};
        for(int i = 0; i < arr.size(); i++) {
            prefix.push_back(prefix.back() + arr[i]);
        }
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int size = 1; i + size - 1 < arr.size(); size += 2) {
                res += prefix[i + size] - prefix[i];
            }
        }
        return res;
    }
}; 

// O(n)
class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> prefix = {0};
        for(int i = 0; i < arr.size(); i++) {
            prefix.push_back(prefix.back() + arr[i]);
        }
        int res = 0;
        for(int i = 0; i < arr.size(); i++) {
            for(int size = 1; i + size - 1 < arr.size(); size += 2) {
                res += prefix[i + size] - prefix[i];
            }
        }
        return res;
    }
}; 