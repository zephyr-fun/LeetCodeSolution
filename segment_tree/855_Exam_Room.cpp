// 2022.12.30
// use a balance tree to maintain optim
class ExamRoom {
public:
    set<int> set;
    int n;
    ExamRoom(int _n) {
        n = _n;
    }
    
    int seat() {
        int p = 0;
        if(!set.empty()) {
            int dist = *set.begin();
            for(auto i = set.begin(); i != set.end(); i++) {
                auto j = i;
                j++;
                if(j != set.end()) {
                    if(dist < (*j - *i) / 2) {
                        dist = (*j - *i) / 2;
                        p = *i + dist;
                    }
                }
                else {
                    if(dist < n - 1 - *i) {
                        dist = n - 1 - *i;
                        p = n - 1;
                    }
                }
            }
        }
        set.insert(p);
        return p;
    }
    
    void leave(int p) {
        set.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(n);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */