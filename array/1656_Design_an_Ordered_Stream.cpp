// 2022.08.16
class OrderedStream {
public:
    vector<string> values;
    int ptr;
    int n;
    OrderedStream(int n_) {
        n = n_;
        values.resize(n + 1, "");
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        vector<string> res;
        values[idKey] = value;
        if(idKey == ptr) {
            while(ptr < n + 1 && values[ptr] != "") {
                res.emplace_back(values[ptr]);
                ptr++;
            }
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */