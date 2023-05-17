// 2022.11.07 update
class Solution {
public:
    int trans(string& event) {
        string h = event.substr(0, 2);
        string m = event.substr(3, 2);
        int hh = 0;
        int mm = 0;
        for(int i = 0; i < 2; i++) {
            hh = hh * 10 + h[i] - '0';
            mm = mm * 10 + m[i] - '0';
        }
        return hh * 60 + mm;
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = trans(event1[0]);
        int start2 = trans(event2[0]);
        int end1 = trans(event1[1]);
        int end2 = trans(event2[1]);
        if(end1 < start2 || end2 < start1) {
            return false;
        }
        return true;
    }
};

// 2023.05.17
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return !(event1[0] > event2[1] || event1[1] < event2[0]);
    }
};