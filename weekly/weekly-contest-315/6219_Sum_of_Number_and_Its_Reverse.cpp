// 2022.10.16
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++) {
            int temp = 0;
            string s = to_string(i);
            for(int j = s.size() - 1; j >= 0; j--){
                temp *= 10;
                temp += s[j] - '0';
            }
            if(i + temp == num) {
                return true;
            }
        }
        return false;
    }
};

// no string
class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for(int i = 0; i <= num; i++) {
            int temp = 0;
            int j = i;
            while(j) {
                temp = temp * 10 + j % 10;
                j /= 10;
            }
            if(i + temp == num) {
                return true;
            }
        }
        return false;
    }
};