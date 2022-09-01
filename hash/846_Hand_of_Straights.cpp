// 2022.09.01
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) {
            return false;
        }
        unordered_map<int, int> map;
        for(auto h : hand) {
            map[h]++;
        }
        vector<int> temp;
        for(auto& [k, v] : map) {
            temp.emplace_back(k);
        }
        sort(temp.begin(), temp.end());
        for(auto& t : temp) {
            if(map[t] == 0) {
                continue;
            }
            int cnt = map[t];
            for(int i = t; i < t + groupSize; i++) {
                if(!map.count(i)) {
                    return false;
                }
                map[i] -= cnt;
                if(map[i] < 0) {
                    return false;
                }
            }
        }
        for(auto& [k, v] : map) {
            if(v != 0) {
                return false;
            }
        }
        return true;
    }
};