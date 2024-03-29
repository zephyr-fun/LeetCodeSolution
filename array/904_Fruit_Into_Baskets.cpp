class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int leftKind = fruits[left];
        int rightKind = fruits[right];
        int res = 0;
        while(right < fruits.size()){
            if(fruits[right] == rightKind || fruits[right] == leftKind){
                res = res > (right - left + 1) ? res : (right - left + 1);
                right++;
            }
            else{
                left = right - 1;
                leftKind = fruits[left];
                while(left > 0 && fruits[left - 1] == leftKind){// order matters "fruits[left - 1] == leftKind && left > 0" bound overflow
                    left--;
                }
                rightKind = fruits[right];
                res = res > (right - left + 1) ? res : (right - left + 1);
            }
        }
        return res;
    }
};

// 2022.04.16
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int leftKind = fruits[left];
        int rightKind = fruits[right];
        int res = INT_MIN;
        while(right < fruits.size()) {
            if(fruits[right] == leftKind || fruits[right] == rightKind) {
                res = res > right - left + 1 ? res : right - left + 1;
                right++;
            }
            else {
                left = right - 1;
                leftKind = fruits[left];
                while(left > 0 && fruits[left - 1] == leftKind){
                    left--;
                }
                rightKind = fruits[right];
                res = res > right - left + 1 ? res : right - left + 1;
            }
        }
        return res;
    }
};

// 2022.10.17
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        unordered_map<int, int> map;
        int res = 0;
        int n = fruits.size();
        while(right < n) {
            map[fruits[right]]++;
            right++;
            while(left <= right && map.size() > 2) {
                map[fruits[left]]--;
                if(map[fruits[left]] == 0) {
                    map.erase(fruits[left]);
                }
                left++;
            }
            res = max(res, right - left);
        }
        return res;
    }
};