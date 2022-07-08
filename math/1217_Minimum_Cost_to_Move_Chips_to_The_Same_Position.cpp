// 2022.07.08
// The first move keeps the parity of the element as it is.
// The second move changes the parity of the element.
// Since the first move is free, if all the numbers have the same parity, the answer would be zero.
// Find the minimum cost to make all the numbers have the same parity.
class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int even = 0;
        int odd = 0;
        for(auto pos : position) {
            if(pos & 1) {
                odd++;
            }
            else {
                even++;
            }
        }
        return min(odd, even);
    }
};