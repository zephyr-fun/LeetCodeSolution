// 2022.07.23
class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        int n = ranks.size();
        unordered_map<char, int> smap;
        unordered_map<int, int> rmap;
        for(int i = 0; i < n; i++) {
            smap[suits[i]]++;
            rmap[ranks[i]]++;
        }
        for(auto [k, v] : smap) {
            if(v == 5) {
                return "Flush";
            }
        }
        for(auto [k, v] : rmap) {
            if(v >= 3) {
                return "Three of a Kind";
            }
        }
        for(auto [k, v] : rmap) {
            if(v == 2) {
                return "Pair";
            }
        }
        return "High Card";
    }
};