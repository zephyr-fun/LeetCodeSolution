// 2022.03.27
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        while(1){
            int sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(set.find(sum) != set.end()){
                return false;
            }
            set.insert(sum);
            n = sum;
        }
        
    }
};
// 2022.03.29
class Solution {
public:
    int getSum(int n){
        int sum = 0;
        while(n != 0){
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> set;
        int sum = 0;
        while(true){
            sum = getSum(n);
            if(sum == 1){
                return true;
            }
            if(set.find(sum) != set.end()){
                return false;
            }
            set.insert(sum);
            n = sum;
        }
        
    }
};