// 2022.05.08
class Solution {
public:
    string largestGoodInteger(string num) {
        int maxValue = -1;
        int nowRepeat = 1;
        for(int i = 1; i < num.size(); i++) {
            if(num[i] == num[i - 1]) {
                nowRepeat += 1;
                if(nowRepeat == 3) {
                    maxValue = max(maxValue, stoi(num.substr(i - 2, 3)));
                }
            }
            else {
                nowRepeat = 1;
            }
        }
        if(maxValue == -1) {
            return "";
        }
        return maxValue == 0 ? "000" : to_string(maxValue);
    }
};