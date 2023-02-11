// 2023.02.11
class Solution {
public:
    struct Cmp{
        constexpr bool operator() (pair<char, int>& a, pair<char, int>& b) {
            return b.second > a.second;
        }
    };
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Cmp> pque;
        if(a > 0) {
            pque.push(make_pair('a', a));
        }
        if(b > 0) {
            pque.push(make_pair('b', b));
        }
        if(c> 0) {
            pque.push(make_pair('c', c));
        }
        string res;
        while(!pque.empty()) {
            auto maxi = pque.top();
            pque.pop();
            int size = res.size();
            if(size >= 2 && res[size - 2] == res[size - 1] && res[size - 1] == maxi.first) {
                if(pque.empty()) {
                    break;
                }
                auto submax = pque.top();
                pque.pop();
                res += submax.first;
                submax.second--;
                if(submax.second > 0) {
                    pque.push(submax);
                }
                pque.push(maxi);
            }
            else {
                res += maxi.first;
                maxi.second--;
                if(maxi.second > 0) {
                    pque.push(maxi);
                }
            }
        }
        return res;
    }
};