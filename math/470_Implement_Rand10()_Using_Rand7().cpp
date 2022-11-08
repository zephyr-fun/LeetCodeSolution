// 2022.07.12
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

// plain
class Solution {
public:
    int rand10() {
        while(true) {
            int res = (rand7() - 1) * 7 + rand7() - 1;
            if(res >= 1 && res <= 10) {
                return res;
            }
        }
        return -1;
    }
};

// reduce call
class Solution {
public:
    int rand10() {
        while(true) {
            int res = (rand7() - 1) * 7 + rand7() - 1;
            if(res >= 1 && res <= 40) {
                return res % 10 + 1;
            }
        }
        return -1;
    }
};

// 2022.11.08
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int cur = 0; // 0-48
        while(cur == 0 || cur > 40) {
            cur = (rand7() - 1) * 7 + rand7() - 1;
        }
        if(cur % 10 == 0) {
            return 10;
        }
        return cur % 10;
    }
};