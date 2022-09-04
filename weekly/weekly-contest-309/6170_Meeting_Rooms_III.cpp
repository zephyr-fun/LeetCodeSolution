// 2022.09.04
// self define set sort, but misunderstanding
struct Info {
    int num;
    int end;
    //重载操作符<,自定义排序规则
    bool operator< (const Info &a)const
    {
        //return a.score < score;	//按score由大到小排列
        if(a.end == end) {
            return a.num > num;
        }
        return a.end > end;	//由小到大排列
    }
};
class Solution {
public:

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        unordered_map<int, int> cnt;
        int max = 0;
        int res = -1;
        set<Info> set;
        for(int i = 0; i < n; i++) {
            Info temp;
            temp.num = i;
            temp.end = 0;
            set.insert(temp);
        }
        int idx = 1;
        for(auto& mt : meetings) {
            int len = mt[1] - mt[0];
            Info temp = *set.begin();
            set.erase(temp);
            cnt[temp.num]++;
            temp.end = (temp.end > mt[0] ? temp.end : mt[0]) + len;
            set.insert(temp);
            cout << idx << " " << temp.num << endl;
            idx++;
        }
        for(int i = 0; i < n; i++) {
            if(cnt[i] > max) {
                max = cnt[i];
                res = i;
            }
        }
        return res;
    }
};
// correct understanding
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](auto& a, auto& b) {
            if(a[0] == b[0]) {
                return a[1] < b[1];
            }
            return a[0] < b[0];
        });
        vector<int> cnt(n, 0);
        unordered_map<int, long long> end;
        for(auto& mt : meetings) {
            int len = mt[1] - mt[0];
            long long minVal = end[0];
            int temp = 0;
            bool flag = false;
            for(int i = 0; i < n; i++) {
                if(end[i] <= mt[0]) {
                    end[i] = mt[1];
                    cnt[i]++;
                    flag = true;
                    break;
                }
                if(end[i] < minVal) {
                    minVal = end[i];
                    temp = i;
                }
            }
            if(!flag) {
                cnt[temp]++;
                end[temp] = (long long) end[temp] + (long long) len;
            }
        }
        int max = 0;
        int res = -1;
        for(int i = 0; i < n; i++) {
            if(cnt[i] > max) {
                max = cnt[i];
                res = i;
            }
        }
        return res;
    }
};