// 2023.02.11
// ignore the spacial position of z
class Solution {
public:
    pair<int, int> getPos(char c) {
        int x = (c - 'a') / 5;
        int y = (c - 'a') % 5;
        return make_pair(x, y);
    }
    string alphabetBoardPath(string target) {
        int curx = 0;
        int cury = 0;
        string res = "";
        for(auto& c : target) {
            auto [tarx, tary] = getPos(c);
            int diffx = tarx - curx;
            int diffy = tary - cury;
            if(diffx > 0) {
                while(diffx) {
                    res += 'D';
                    diffx--;
                }
            }
            else if(diffx < 0) {
                diffx *= -1;
                while(diffx) {
                    res += 'U';
                    diffx--;
                }
            }
            if(diffy > 0) {
                while(diffy) {
                    res += 'R';
                    diffy--;
                }
            }
            else if(diffy < 0) {
                diffy *= -1;
                while(diffy) {
                    res += 'L';
                    diffy--;
                }
            }
            res += '!';
            curx = tarx;
            cury = tary;
        }
        return res;
    }
};

// optim
class Solution {
public:
    string alphabetBoardPath(string target) {
        int curx = 0;
        int cury = 0;
        string res = "";
        for(auto& c : target) {
            int tarx = (c - 'a') / 5;
            int tary = (c - 'a') % 5;
            string v(abs(tarx - curx), "UD"[tarx > curx]);
            string h(abs(tary - cury), "LR"[tary > cury]);
            res += c == 'z' ? h + v : v + h;
            res += '!';
            curx = tarx;
            cury = tary;
        }
        return res;
    }
};