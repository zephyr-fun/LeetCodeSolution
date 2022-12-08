// 2022.12.08
// determine the odd or even
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int i = coordinates[0] - 'a' + 1;
        int j = coordinates[1] - '0';
        if((i % 2) == (j % 2)) {
            return false;
        }
        return true;
    }
};

// i + j
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int i = coordinates[0] - 'a' + 1;
        int j = coordinates[1] - '0';
        return (i + j) % 2 == 1;
    }
};