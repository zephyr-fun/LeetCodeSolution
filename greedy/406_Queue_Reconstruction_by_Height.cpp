// 2022.04.06
// version 1 with vector, insert operation cost time
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> queue;
        for(int i = 0; i < people.size(); i++){
            int position = people[i][1];
            queue.insert(queue.begin() + position, people[i]);
        }
        return queue;
    }
};

// version 2 with listnode
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> queue; // stl
        for(int i = 0; i < people.size(); i++){
            int position = people[i][1];
            list<vector<int>>::iterator it = queue.begin(); // iterator it
            while(position--){
                it++;
            }
            queue.insert(it, people[i]); // insert of list
        }
        return vector<vector<int>> (queue.begin(), queue.end());
    }
};

// 2022.06.09
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b [0];
        });
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};

// binary search + BIT

// 2022.06.14
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] > b[0];
        });
        vector<vector<int>> res;
        for(auto& person : people) {
            res.insert(res.begin() + person[1], person);
        }
        return res;
    }
};

// 2022.07.09
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
            if(a[0] != b[0]) {
                return a[0] > b[0];
            }
            return a[1] < b[1];
        });
        int n = people.size();
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            res.insert(res.begin() + people[i][1], people[i]);
        }
        return res;
    }
};