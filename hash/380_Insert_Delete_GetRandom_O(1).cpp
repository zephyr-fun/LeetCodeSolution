// 2022.08.03
static int nums[200007];
class RandomizedSet {
    mt19937 gen;
    unordered_map<int, int> map;
    int idx;
public:
    RandomizedSet() : gen(random_device{}()), idx(0) {

    }
    
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        nums[idx] = val;
        map[val] = idx;
        idx++;
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val)) {
            return false;
        }
        int temp = map[val];
        map.erase(val);
        if(temp != idx - 1) {
            nums[temp] = nums[idx - 1];
            map[nums[idx - 1]] = temp;
        }
        idx--;
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> dist(0, idx - 1);
        return nums[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// 2022.09.02
static int nums[200007];
class RandomizedSet {
    mt19937 gen;
    unordered_map<int, int> map;
    int idx;
public:
    RandomizedSet() : gen(random_device{}()), idx(0) {

    }
    
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        nums[idx] = val;
        map[val] = idx;
        idx++;
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val)) {
            return false;
        }
        int temp = map[val];
        map.erase(val);
        if(temp != idx - 1) {
            nums[temp] = nums[idx - 1];
            map[nums[idx - 1]] = temp;
        }
        idx--;
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> dist(0, idx - 1);
        return nums[dist(gen)];
    }
};


// 2023.05.12
static int nums[200007];
class RandomizedSet {
public:
    mt19937 gen;
    unordered_map<int, int> map;
    int idx;
    RandomizedSet() : gen(random_device{}()), idx(0) {}
    
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        nums[idx] = val;
        map[val] = idx;
        idx++;
        return true;
    }
    
    bool remove(int val) {
        if(!map.count(val)) {
            return false;
        }
        int temp_idx = map[val];
        map.erase(val);
        if(temp_idx != idx - 1) {
            nums[temp_idx] = nums[idx - 1];
            map[nums[idx - 1]] = temp_idx;
        }
        idx--;
        return true;
    }
    
    int getRandom() {
        uniform_int_distribution<> dist(0, idx - 1);
        return nums[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */