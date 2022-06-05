// 2022.06.06
// solution 1
class MyCalendarThree {
public:
    MyCalendarThree() {

    }
    
    int book(int start, int end) {
        deltas_[start]++;
        deltas_[end]--;
        int res = 0;
        int cur = 0;
        for(const auto& kv : deltas_) {
            res = max(res, cur += kv.second);
        }
        return res;
    }
private:
    map<int, int> deltas_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

// solution 2
// huahua
class MyCalendarThree {
public:
    MyCalendarThree(): max_count_(0) {
        root_.reset(new Node(0, 100000000, 0));        
    }
    
    int book(int start, int end) {
        Add(start, end, root_.get());
        return max_count_;
    }
private:
    struct Node {
        Node(int l, int r, int count):l(l), m(-1), r(r), count(count){}
        int l;
        int m;
        int r;
        int count;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
    };
    
    void Add(int start, int end, Node* root) {
        if (root->m != -1) {
            if (end <= root->m) 
                Add(start, end, root->left.get());
            else if(start >= root->m)
                Add(start, end, root->right.get());
            else {
                Add(start, root->m, root->left.get());
                Add(root->m, end, root->right.get());
            }
            return;
        }
        
        if (start == root->l && end == root->r)
            max_count_ = max(max_count_, ++root->count);
        else if (start == root->l) {
            root->m = end;
            root->left.reset(new Node(start, root->m, root->count + 1));
            root->right.reset(new Node(root->m, root->r, root->count));
            max_count_ = max(max_count_, root->count + 1);
        } else if(end == root->r) {
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count + 1));
            max_count_ = max(max_count_, root->count + 1);
        } else {
            root->m = start;
            root->left.reset(new Node(root->l, root->m, root->count));
            root->right.reset(new Node(root->m, root->r, root->count));
            Add(start, end, root->right.get());
        }
    }
    
    std::unique_ptr<Node> root_;
    int max_count_;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */

// solution 3
class MyCalendarThree {
private:
    unordered_map<int, int> tree;
    unordered_map<int, int> lazy;
public:
    MyCalendarThree() {

    }
    
    void update(int start, int end, int left, int right, int node) {
        if(start > right || end < left) {
            return ;
        }
        else if(start <= left && end >= right) {
            tree[node]++;
            lazy[node]++;
        }
        else {
            int left_node = 2 * node;
            int right_node = 2 * node + 1;
            int mid = left + (right - left) / 2;
            update(start, end, left, mid, left_node);
            update(start, end, mid + 1, right);
            tree[node] = lazy[node] + max(tree[left_node], tree[right_node]);
        }
    }

    int book(int start, int end) {
        update(start, end - 1, 0, 1e9, 1);
        return tree[1];
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */