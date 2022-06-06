// 2022.06.06
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        int n = chalk.size();
        for(int i = 0; i < n; i++) {
            sum += chalk[i];
        }
        while(k >= sum) {
            k -= sum;
        }
        for(int i = 0; i < n; i++) {
            if(chalk[i] > k) {
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};

//
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        int count = 0;
        while(k >= 0) {
            k -= chalk[count % n];
            count++;
        }
        return (count - 1) % n;
    }
};