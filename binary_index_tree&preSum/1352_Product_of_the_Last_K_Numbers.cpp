// 2022.07.20
class ProductOfNumbers {
public:
    int prefix[40007];
    int len = 0;
    ProductOfNumbers() {
        memset(prefix, 0, sizeof(prefix));
        prefix[0] = 1;
    }
    
    void add(int num) {
        if(num == 0) {
            len = 0;
        }
        else {
            len++;
            prefix[len] = prefix[len - 1] * num;
        }
    }
    
    int getProduct(int k) {
        return len >= k ? prefix[len] / prefix[len - k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

// 2022.07.28
class ProductOfNumbers {
public:
    int prod[40007];
    int len = 0;
    ProductOfNumbers() {
        memset(prod, 0, sizeof(prod));
         prod[0] = 1;
    }
    
    void add(int num) {
        if(num == 0) {
            len = 0;
        }
        else {
            len++;
            prod[len] = num * prod[len - 1];
        }
    }
    
    int getProduct(int k) {
        return len >= k ? prod[len] / prod[len - k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */