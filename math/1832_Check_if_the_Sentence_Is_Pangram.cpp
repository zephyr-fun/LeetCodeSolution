// 2022.12.13
class Solution {
public:
    bool checkIfPangram(string sentence) {
        int mask = (1 << 26) - 1;
        int cur = 0;
        for(auto& c : sentence) {
            cur |= (1 << (c - 'a'));
        }
        return cur == mask;
    }
};