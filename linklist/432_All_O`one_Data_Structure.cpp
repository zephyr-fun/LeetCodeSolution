// 2023.05.05
// LFU cache like
// bi-linklist & hash map
class AllOne {
public:
    struct Node {
        Node* left;
        Node* right;
        int val;
        unordered_set<string> S;
        Node(int val_) {
            val = val_;
            left = right = nullptr;
        }
    }*left, *right;

    unordered_map<string, Node*> map;

    AllOne() {
        left = new Node(INT_MIN);
        right = new Node(INT_MAX);
        left->right = right;
        right->left = left;
    }
    
    Node* add_to_right(Node* node, string key, int val) {
        if(node->right->val == val) {
            node->right->S.insert(key);
        }
        else {
            auto t = new Node(val);
            t->S.insert(key);
            t->right = node->right;
            node->right->left = t;
            node->right = t;
            t->left = node;
        }
        return node->right;
    }

    Node* add_to_left(Node* node, string key, int val) {
        if(node->left->val == val) {
            node->left->S.insert(key);
        }
        else {
            auto t = new Node(val);
            t->S.insert(key);
            t->left = node->left;
            node->left->right = t;
            node->left = t;
            t->right = node;
        }
        return node->left;
    }

    void remove(Node* node) {
        node->left->right = node->right;
        node->right->left = node->left;
        delete node;
        return ;
    }

    void inc(string key) {
        if(!map.count(key)) {
            map[key] = add_to_right(left, key, 1);
        }
        else {
            auto t = map[key];
            t->S.erase(key);
            map[key] = add_to_right(t, key, t->val + 1);
            if(t->S.empty()) {
                remove(t);
            }
        }
    }
    
    void dec(string key) {
        if(!map.count(key)) {
            return ;
        }
        auto t = map[key];
        t->S.erase(key);
        if(t->val > 1) {
            map[key] = add_to_left(t, key, t->val - 1);
        }
        else {
            map.erase(key);
        }
        if(t->S.empty()) {
            remove(t);
        }
    }
    
    string getMaxKey() {
        if(right->left != left) {
            return *right->left->S.begin();
        }
        return "";
    }
    
    string getMinKey() {
        if(left->right != right) {
            return *left->right->S.begin();
        }
        return "";
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */