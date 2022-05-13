// 2022.05.13
class Solution {
public:
    bool oneEditAway(string first, string second) {
        if(first.size() > second.size()) {
            return oneEditAway(second, first);
        }
        // make sure the first string len <= second string len
        int firstSize = first.size();
        int secondSize = second.size();
        if(secondSize - firstSize > 1) {
            return false;
        }
        int i = 0;
        int j = 0;
        int cnt = 0; // edit number
        while(i < firstSize && j < secondSize && cnt <= 1) {
            if(first[i] == second[j]) { // char equal
                i++;
                j++;
            }
            else {
                if(firstSize == secondSize) { // you can only get same char by changing one of them
                    i++;
                    j++;
                    cnt++;
                }
                else { // insert to first (cause first is shorter than second)
                    j++;
                    cnt++;
                }
            }
        }
        return cnt > 1 ? false : true;
    }
};