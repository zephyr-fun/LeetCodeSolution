// 2022.07.23
class NumberContainers {
public:
    unordered_map<int, int> simVec;
    unordered_map<int, set<int>> map;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(simVec.count(index)) {
            int temp = simVec[index];
            simVec[index] = number;
            map[temp].erase(index);
            if(map[temp].size() == 0) {
                map.erase(temp);
            }
            map[number].insert(index);
        }
        else {
            simVec[index] = number;
            map[number].insert(index);
        }
    }
    
    int find(int number) {
        if(map.count(number)) {
            return *map[number].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */