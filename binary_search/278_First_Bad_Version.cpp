// 2022.08.25
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int res = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2; // (left + right) >> 1 will overflow
            if(isBadVersion(mid)) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int res = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(isBadVersion(mid)) {
                right = mid - 1;
            }
            else {
                res = mid;
                left = mid + 1;
            }
        }
        return res + 1;
    }
};