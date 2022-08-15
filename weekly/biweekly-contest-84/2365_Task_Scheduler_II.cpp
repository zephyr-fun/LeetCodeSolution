// 2022.08.06 contest 2022.08.15 update
class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long cur = 0;
        unordered_map<long long, long long> map;
        int n = tasks.size();
        //
        // int len1 = tasks.size();
        // for(auto task : tasks) {
        //     map[task]++;
        // }
        // int maxVal = 0;
        // int cnt = 0;
        // for(auto [k, v] : map) {
        //     if(v > maxVal) {
        //         maxVal = v;
        //         cnt = 1;
        //     }
        //     else if(v == maxVal) {
        //         cnt++;
        //     }
        // }
        // int len2 = (maxVal - 1) * (space + 1) + cnt;
        // return max(len1, len2);
        //
        for(int i = 0; i < n; i++) {
            if(map.count(tasks[i])) {
                // cout << "yes" << i << tasks[i] << map[tasks[i]] << endl;
                if(cur <= map[tasks[i]]) {
                    cur = map[tasks[i]];
                    map[tasks[i]] += space + 1;
                    cur++;
                    
                }
                else {
                    map[tasks[i]] = cur + space + 1;
                    cur++;
                }
            }
            else {
                // cout << "no" << i << tasks[i] << map[tasks[i]] << endl;
                map[tasks[i]] = cur + space + 1;
                cur++;
            }
            // cout << cur << endl;
        }
        return cur;
    }
};