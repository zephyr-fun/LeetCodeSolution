// 2023.02.05
class Solution {
public:
    string maximumTime(string time) {
        int n = time.size();
        for(int i = 0; i < n; i++) {
            if(time[i] == '?') {
                if(i == 0) {
                    if(time[i + 1] == '?' || time[i + 1] <= '3') {
                        time[i] = '2';
                    }
                    else {
                        time[i] = '1';
                    }
                }
                else if(i == 1) {
                    if(time[0] == '2') {
                        time[i] = '3';
                    }
                    else {
                        time[i] = '9';
                    }
                }
                else if(i == 3) {
                    time[i] = '5';
                }
                else if(i == 4) {
                    time[i] = '9';
                }
            }
        }
        return time;
    }
};