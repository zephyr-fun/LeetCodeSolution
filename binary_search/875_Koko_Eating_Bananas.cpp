// 2022.05.18
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1;
        int right = piles[piles.size() - 1];
        int res = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(totalTime(piles, mid) > h) {
                left = mid + 1;
            }
            else {
                res = mid;
                right = mid - 1;
            }
        }
        return res;
    }
    int totalTime(vector<int>& piles, int k) {
        int res = 0;
        for(int i = 0; i < piles.size(); i++) {
            res += piles[i] % k == 0 ? piles[i] / k : piles[i] / k + 1;
        }
        return res;
    }
};

// 2022.06.07
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int left = 1;
        int right = piles[piles.size() - 1];
        int res = 0;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(totalTime(piles, mid) <= h) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
    int totalTime(vector<int>& piles, int speed) {
        int res = 0;
        for(int i = 0; i < piles.size(); i++) {
            res += piles[i] % speed == 0 ? piles[i] / speed : piles[i] / speed + 1;
        }
        return res;
    }
};