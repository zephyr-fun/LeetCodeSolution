class NumArray {
    /* 两类操作
    1. 更新数组下标对应的值
    2. 返回某个范围内的元素总和
    // 但节点修改的线段树，不需要设置懒标记
    */
  private:
    void build_tree(vector<int> &nums, int tr[], int node, int start, int end) {
        /*
        建立线段树
        node是要建立的当前节点，start和end是节点的范围,两端包含
        注意：下标从0开始
        */
        if (start == end) { // 建立当前节点
            tr[node] = nums[start];
        } else {
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int mid = (start + end) / 2;
            build_tree(nums, tr, left_node, start, mid);
            build_tree(nums, tr, right_node, mid + 1, end);
            tr[node] = tr[left_node] + tr[right_node];
        }
    }
    void update_tree(int tr[], int node, int start, int end, int idx, int val) {
        /*
        修改线段树
        将下标idx改为val,node是线段树节点序号，start和end是线段树节点在原数组的范围
         */
        if (start == end) {
            tr[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int left_node = 2 * node + 1;
        int right_node = 2 * node + 2;
        if (idx < start || idx > end) return;
        if (start <= idx && idx <= mid) { // 修改左分支
            update_tree(tr, left_node, start, mid, idx, val);
        } else { // 修改右分支
            update_tree(tr, right_node, mid + 1, end, idx, val);
        }
        tr[node] = tr[left_node] + tr[right_node];
    }
    int query_tree(int tr[], int node, int start, int end, int L, int R) {
        /*
        线段树查询，
        查询区间L,R的和，两端包含
         */
        if (R < start || L > end)
            return 0;
        else if (start == end)
            return tr[node];
        else if (start >= L && end <= R)
            return tr[node];
        else {
            int mid = (start + end) / 2;
            int left_node = 2 * node + 1;
            int right_node = 2 * node + 2;
            int sum_left = query_tree(tr, left_node, start, mid, L, R);
            int sum_right = query_tree(tr, right_node, mid + 1, end, L, R);
            return sum_left + sum_right;
        }
    }
    // int tr[120000];
    int *tr;
    int n;

  public:
    NumArray(vector<int> &nums) {
        /* 使用nums初始化线段树，下标从0开始 */
        n = nums.size();
        tr = new int[n * 4];
        memset(tr, 0, sizeof(tr));
        build_tree(nums, tr, 0, 0, n - 1);
    }
    ~NumArray() { delete[] tr; }

    void update(int index, int val) {
        /* 更新对象中的值 */
        update_tree(tr, 0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        /* 区域求和 */
        int res = query_tree(tr, 0, 0, n - 1, left, right);
        return res;
    }
};