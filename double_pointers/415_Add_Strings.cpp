// 2022.07.26
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while(i >= 0 && j >= 0) {
            int temp = num1[i] - '0' + num2[j] - '0' + carry;
            int cur = temp % 10;
            carry = temp / 10;
            res = to_string(cur) + res;
            i--;
            j--;
        }
        while(i >= 0) {
            int temp = num1[i] - '0' + carry;
            int cur = temp % 10;
            carry = temp / 10;
            res = to_string(cur) + res;
            i--;
        }
        while(j >= 0) {
            int temp = num2[j] - '0' + carry;
            int cur = temp % 10;
            carry = temp / 10;
            res = to_string(cur) + res;
            j--;
        }
        if(carry) {
            cout << carry << endl;
            res = '1' + res;
        }
        return res;
    }
};