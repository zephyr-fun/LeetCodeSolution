// 2023.01.14
class MajorityChecker {
public:
    static const int N = 20010;
    struct Node{
        int l {}, r {};
        int cnt {};
    } tr[N * 4 + N * 14];
    int root[N] {}, idx = 0;
    vector<int> nums;

    //递归建树
    int build(int l, int r) {
        int p = ++ idx;
        if(l == r) return p;
        int mid = l + r >> 1;
        tr[p].l = build(l, mid), tr[p].r = build(mid + 1, r);
        return p;
    }

    //插入新根节点
    int insert(int p, int l, int r, int x) {
        int q = ++ idx;
        tr[q] = tr[p];
        if(l == r) {
            tr[q].cnt ++;
            return q;
        }
        int mid = l + r >> 1;
        if(x <= mid) tr[q].l = insert(tr[p].l, l, mid, x);
        else tr[q].r = insert(tr[p].r, mid + 1, r, x);
        tr[q].cnt = tr[tr[q].l].cnt + tr[tr[q].r].cnt;
        return q;
    }
    
    //二分查询
    int query(int p, int q, int l, int r, int k) {
        int cnt = tr[tr[q].l].cnt - tr[tr[p].l].cnt;
        if(l == r) {
            if(tr[q].cnt - tr[p].cnt >= k) return nums[l];
            return -1;
        }
        int mid = l + r >> 1;
        if(k <= cnt) return query(tr[p].l, tr[q].l, l, mid, k);
        return query(tr[p].r, tr[q].r, mid + 1, r, k);
    }

    MajorityChecker(vector<int>& arr) {
        nums = arr;
        //离散化
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        root[0] = build(0, nums.size() - 1);
        int n = arr.size();
        for(int i = 1; i <= n; i ++) {
            root[i] = insert(root[i - 1], 0, nums.size() - 1, lower_bound(nums.begin(), nums.end(), arr[i - 1]) - nums.begin());
        }
    }
    
    int query(int left, int right, int threshold) {
        return query(root[left], root[right + 1], 0, nums.size() - 1, threshold);
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */