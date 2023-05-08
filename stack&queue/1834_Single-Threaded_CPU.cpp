// 2023.05.07
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<task> tsks;
        for (int i = 0; i < tasks.size(); i++) {
            tsks.emplace_back(i, tasks[i][0], tasks[i][1]);
        }
        // 入参不一定是按加入cpu的顺序排序的, 因此还需要按加入时间排一下序
        sort(tsks.begin(), tsks.end(), [](task& t1, task& t2) {
            // 按加入cpu时间对任务列表进行排序
            return t1.enqueTime < t2.enqueTime;
        });
        vector<int> res;
        priority_queue<task> cpuQue; // 模拟cpu队列
        long time = 0; // 当前时间
        int i = 0; // 下一个加入cpu队列的下标

        while (i < tsks.size() || !cpuQue.empty()) {
            if (cpuQue.empty()) {
                // 待执行队列为空, 如果当前cpu空闲则时间直接跳到下一次入队
                time = max(time, tsks[i].enqueTime);
            }

            // 在执行的过程中继续将新的任务加入cpu队列
            while (i < tsks.size() && tsks[i].enqueTime <= time) {
                cpuQue.push(tsks[i]);
                i++;
            }

            // 处理任务
            task procTask = cpuQue.top();
            cpuQue.pop();
            time += procTask.procTime;
            res.emplace_back(procTask.index);
        }
        return res;
    }
    struct task {
        task(int i, long e, long p) {
            index = i;
            enqueTime = e;
            procTime = p;
        }
        bool operator < (const task& other) const {
            if (procTime != other.procTime) {
                // CPU 将会选择 执行时间最短 的任务开始执行
                return procTime > other.procTime;
            }
            // 如果多个任务具有同样的最短执行时间，则选择下标最小的任务开始执行
            return index > other.index;
        }
        int index;
        long enqueTime, procTime;
    };
};

// localize
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<task> tks;
        for(int i = 0; i < tasks.size(); i++) {
            tks.emplace_back(i, tasks[i][0], tasks[i][1]);
        }
        sort(tks.begin(), tks.end(), [](task& a, task& b) {
            if(a.enqueTime == b.enqueTime) {
                return a.procTime < b.procTime;
            }
            return a.enqueTime < b.enqueTime;
        });
        vector<int> res;
        priority_queue<task> cpuQue;
        long time = 0;
        int i = 0;
        while(i < tks.size() || !cpuQue.empty()) {
            if(cpuQue.empty()) {
                time = max(time, tks[i].enqueTime);
            }
            while(i < tks.size() && tks[i].enqueTime <= time) {
                cpuQue.push(tks[i]);
                i++;
            }
            task curTask = cpuQue.top();
            cpuQue.pop();
            time += curTask.procTime;
            res.emplace_back(curTask.index);
        }
        return res;
    }
    struct task {
        int index;
        long enqueTime, procTime;
        task(int i, long e, long p) {
            index = i;
            enqueTime = e;
            procTime = p;
        }
        bool operator < (const task& other) const {
            if (procTime != other.procTime) {
                return procTime > other.procTime;
            }
            return index > other.index;
        }
    };
};