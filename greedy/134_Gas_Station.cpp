// O(n*2) overtime
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for(int i = 0; i < gas.size(); i++){
            int rest = gas[i] - cost[i];
            int index = (i + 1) % cost.size();
            while(rest > 0 && index != i){
                rest += gas[index] - cost[index];
                index = (index + 1) % cost.size();
            }
            if(rest >= 0 && index == i){
                return i;
            }
        }
        return -1;
    }
};
// greedy 1
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int min = INT_MAX;
        for(int i = 0; i < gas.size(); i++){
            int rest = gas[i] - cost[i];
            curSum += rest;
            if(min > curSum){
                min = curSum;
            }
        }
        if(curSum < 0){
            return -1;
        }
        if(min >= 0){
            return 0;
        }
        for(int i = gas.size() - 1; i > 0; i--){
            int rest = gas[i] - cost[i];
            min += rest;
            if(min >= 0){
                return i;
            }
        }
        return -1;
    }
};
// greedy 2
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for(int i = 0; i < gas.size(); i++){
            curSum += gas[i] - cost[i];
            totalSum += gas[i] - cost[i];
            if(curSum < 0){
                start = i + 1;
                curSum = 0;
            }
        }
        if(totalSum < 0){
            return -1;
        }
        return start;
    }
};

// 2022.07.09
// rest = 驶离当前加油站时的剩余油量
// rest 最终代表跑完一圈的剩余油量，假设小于0则不可能跑完一圈
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int rest = 0;
        int minRest = 0x3f3f3f3f;
        int res = 0;
        for(int i = 0; i < n; i++) {
            rest += gas[i] - cost[i];
            if(rest < minRest) {
                minRest = rest;
                res = i;
            }
        }
        return rest < 0 ? -1 : (res + 1) % n;
    }
};