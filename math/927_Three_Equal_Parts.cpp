// 2022.10.06
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 3 != 0) {
            return {-1, -1};
        }
        else if(sum == 0) {
            return {0, 2};
        }
        int each = sum / 3;
        int first = -1;
        int second = -1;
        int third = -1;
        int cur = 0;
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] == 1) {
                if(cur == 0) {
                    first = i;
                }
                else if(cur == each) {
                    second = i;
                }
                else if(cur == 2 * each) {
                    third = i;
                }
                cur++;
            }
        }
        int len = arr.size() - third;
        if(first + len <= second && second + len <= third) {
            int i = 0;
            while(third + i < arr.size()) {
                if(arr[first + i] != arr[third + i] || arr[second + i] != arr[third + i]) {
                    return {-1, -1};
                }
                i++;
            }
            return {first + len - 1, second + len};
        }
        return {-1, -1};
    }
};