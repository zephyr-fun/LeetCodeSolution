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
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        preOrder(root, res);
        return res;
    }
    void preOrder(Node* root, vector<int>& res) {
        if(root == nullptr){
            return ;
        }
        for(auto child : root->children){
            if(child != nullptr){
                preOrder(child, res);
            }
        }
        res.push_back(root->val);
    }
};

// non recursion
class Solution {
public:
    
    vector<int> preorder(Node* root) {
        vector<int> res;
        stack<Node*> st;
        if(root != nullptr){
            st.push(root);
        }
        while(!st.empty()){
            Node* node = st.top();
            if(node != nullptr){
                st.pop();
                reverse(node->children.begin(), node->children.end());
                for(auto child : node->children){
                    st.push(child);
                }
                reverse(node->children.begin(), node->children.end());
                st.push(node);
                st.push(nullptr);
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