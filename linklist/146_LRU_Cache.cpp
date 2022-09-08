// 2022.09.08
class LRUCache {
public:
    struct Node {
        int key;
        int val;
        Node* left;
        Node* right;
        Node(int _key, int _val) : key(_key), val(_val), left(nullptr), right(nullptr) {}
    };
    Node* l;
    Node* r;
    unordered_map<int, Node*> map;
    int n;

    void remove(Node* p) {
        p->left->right = p->right;
        p->right->left = p->left;
    }

    void insert(Node* p) {
        p->right = l->right;
        l->right->left = p;
        p->left = l;
        l->right = p;
    }

    LRUCache(int capacity) {
        n = capacity;
        l = new Node(-1, -1);
        r = new Node(-1, -1);
        l->right = r;
        r->left = l;
    }
    
    int get(int key) {
        if(!map.count(key)) {
            return -1;
        }
        auto p = map[key];
        remove(p);
        insert(p);
        return p->val;
    }
    
    void put(int key, int value) {
        if(map.count(key)) {
            auto p = map[key];
            p->val = value;
            remove(p);
            insert(p);
        }
        else {
            if(map.size() == n) {
                auto p = r->left;
                remove(p);
                map.erase(p->key);
                delete p;
            }
            auto p = new Node(key, value);
            map[key] = p;
            insert(p);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */