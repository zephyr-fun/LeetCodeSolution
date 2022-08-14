// 2022.08.03
static int nums[200010];
class RandomizedSet {
    mt19937 gen;
    unordered_map<int, int> map;
    int idx;
public:
    /** Initialize your data structure here. */
    RandomizedSet() : gen(random_device{}()), idx(0) {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        map[val] = idx;
        nums[idx] = val;
        idx++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
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
    
    /** Get a random element from the set. */
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

// 2022.08.12
static int num[200010];
class RandomizedSet {
public:
    int idx;
    mt19937 gen;
    unordered_map<int, int> map;
    /** Initialize your data structure here. */
    RandomizedSet() : gen(random_device{} ()), idx(0) {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        num[idx] = val;
        map[val] = idx;
        idx++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!map.count(val)) {
            return false;
        }
        int temp = map[val];
        map.erase(val);
        if(temp != idx - 1) {
            num[temp] = num[idx - 1];
            map[num[idx - 1]] = temp;
        }
        idx--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<> dist(0, idx - 1);
        return num[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// 2022.08.14
static int num[200007];
class RandomizedSet {
public:
    int idx;
    mt19937 gen;
    unordered_map<int, int> map;
    /** Initialize your data structure here. */
    RandomizedSet() : idx(0), gen(random_device{}()) {

    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(map.count(val)) {
            return false;
        }
        map[val] = idx;
        num[idx] = val;
        idx++;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(!map.count(val)) {
            return false;
        }
        int temp = map[val];
        map.erase(val);
        if(temp != idx - 1) {
            num[temp] = num[idx - 1];
            map[num[idx - 1]] = temp;
        }
        idx--;
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution dist(0, idx - 1);
        return num[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */