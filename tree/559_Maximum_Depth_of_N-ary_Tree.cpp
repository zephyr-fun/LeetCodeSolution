/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
// 2022.03.18
//recursion
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int res = 0;
        for(auto child : root->children){
            res = max(res, maxDepth(child));
        }
        // postorder traversal
        return res + 1;
    }
};

// backtrack
class Solution {
public:
    int res;
    int maxDepth(Node* root) {
        res = 0;
        if(root == nullptr) return res;
        getDepth(root, 1);
        return res;
    }
    void getDepth(Node* root, int depth){
        // preorder traversal
        res = depth > res ? depth : res;
        if(root == nullptr) return;
        for(auto child : root->children){
            if(child != nullptr){
                depth++;
                getDepth(child, depth);
                depth--;
            }
        }
    }
};

// 2022.04.27
class Solution {
public:
    int maxDepth(Node* root) {
        // would never exec this part of code
        if(root == nullptr) {
            return 0;
        }
        // would never exec this part of code

        int tempMax = 0; // so init tempMax = 0 matters
        for(auto child : root->children) {
            int temp = maxDepth(child);
            tempMax = max(tempMax, temp);
        }
        return tempMax + 1;
    }
};