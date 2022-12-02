// 2022.12.02
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        for(int i = 0; i < n; i++) {
            if(boxes[i] == '0') {
                continue;
            }
            for(int j = 0; j < n; j++) {
                res[j] += abs(i - j);
            }
        }
        return res;
    }
};

// optim
// inference based on res[i - 1], left, right
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> res(n, 0);
        int left = 0;
        int right = 0;
        for(int i = 1; i < n; i++) {
            if(boxes[i] == '0') {
                continue;
            }
            res[0] += i;
            right++;
        }
        for(int i = 1; i < n; i++) {
            if(boxes[i - 1] == '1') {
                left++;
            }
            res[i] = res[i - 1] + left - right;
            if(boxes[i] == '1') {
                right--;
            }
        }
        return res;
    }
};