// 2023.01.26
class Solution {
public:
    string getSmallestString(int n, int k) {
        int left = k - n;
        vector<int> temp(n, 1);
        int idx = n - 1;
        while(left) {
            while(left && temp[idx] < 26) {
                temp[idx]++;
                left--;
            }
            idx--;
        }
        string res;
        for(auto& num : temp) {
            res += 'a' + num - 1;
        }
        return res;
    }
};

// optim
class Solution {
public:
    string getSmallestString(int n, int k) {
        string res(n, 'a');
        int idx = n - 1;
        int left = k - n;
        for (; left > 25; left -= 25) {
            res[idx--] = 'z';
        }
        res[idx] += left;
        return res;
    }
};