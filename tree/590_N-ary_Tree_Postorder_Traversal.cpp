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
// recursion
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        postOrder(root, res);
        return res;
    }
    void postOrder(Node* root, vector<int>& res) {
        if(root == nullptr){
            return ;
        }
        for(auto child : root->children){
            if(child != nullptr){
                postOrder(child, res);
            }
        }
        res.push_back(root->val);
    }
};
// non recursion
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if(root != nullptr){
            st.push(root);
        }
        while(!st.empty()){
            Node* node = st.top();
            if(node != nullptr){
                st.pop();
                //postorder;
                st.push(node);
                st.push(nullptr);
                reverse(node->children.begin(), node->children.end());
                for(auto child : node->children){
                    if(child != nullptr){
                        st.push(child);
                    }
                }
                reverse(node->children.begin(), node->children.end());
            }
            else{
                st.pop();
                node = st.top();
                st.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }
};

// 2022.04.27
class Solution {
public:
    void traversal(Node* root, vector<int>& res) {
        if(root == nullptr) {
            return ;
        }
        for(auto child : root->children) {
            traversal(child, res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
};