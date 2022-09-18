// 2022.09.17
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for(int i = 1; i < 13; i++) {
            days[i] = days[i - 1] + days[i];
        }
        int ast = days[stoi(arriveAlice.substr(0, 2)) - 1] + stoi(arriveAlice.substr(3, 2));
        int aed = days[stoi(leaveAlice.substr(0, 2)) - 1] + stoi(leaveAlice.substr(3, 2));
        int bst = days[stoi(arriveBob.substr(0, 2)) - 1] + stoi(arriveBob.substr(3, 2));
        int bed = days[stoi(leaveBob.substr(0, 2)) - 1] + stoi(leaveBob.substr(3, 2));
        if(ast > bed || bst > aed) {
            return 0;
        }
        return min(aed, bed) - max(ast, bst) + 1;
    }
};