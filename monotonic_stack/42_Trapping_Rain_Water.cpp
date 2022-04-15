// 2022.04.15
// double pointers, O(n^2), over time
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            if(i == 0 || i == height.size() - 1){
                continue;
            }
            int leftHeight = height[i];
            int rightHeight = height[i];
            for(int l = i - 1; l >= 0; l--){
                if(height[l] > leftHeight){
                    leftHeight = height[l];
                }
            }
            for(int r = i + 1; r < height.size(); r++){
                if(height[r] > rightHeight){
                    rightHeight = height[r];
                }
            }
            sum += min(leftHeight, rightHeight) - height[i];
        }
        return sum;
    }
};

// dp O(n)
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        vector<int> maxLeft(height.size(), 0);
        vector<int> maxRight(height.size(), 0);
        maxLeft[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            maxLeft[i] = max(maxLeft[i - 1], height[i]);
        }
        maxRight[height.size() - 1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            maxRight[i] = max(maxRight[i + 1], height[i]);
        }
        int sum = 0;
        for(int i = 0; i < height.size(); i++){
            int count = min(maxLeft[i], maxRight[i]) - height[i];
            if(count > 0){
                sum += count;
            }
        }
        return sum;
    }
};

// monotonic stack
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2){
            return 0;
        }
        stack<int> st;
        st.push(0);
        int sum = 0;
        for(int i = 1; i < height.size(); i++){
            if(height[i] < height[st.top()]){
                st.push(i);
            }
            else if(height[i] == height[st.top()]){
                st.pop();
                st.push(i);
            }
            else{
                while(!st.empty() && height[i] > height[st.top()]){
                    int mid = st.top();
                    st.pop();
                    if(!st.empty()){
                        int h = min(height[st.top()], height[i]) - height[mid];
                        int w = i - st.top() - 1;
                        sum += h * w;
                    }
                }
                st.push(i);
            }
        }
        return sum;
    }
};
