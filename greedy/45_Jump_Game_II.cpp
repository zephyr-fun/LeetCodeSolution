// 2022.04.06
class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int curCover = 0;
        int nextCover = 0;
        int res = 0;
        for(int i = 0; i < nums.size(); i++){
            nextCover = max(i + nums[i], nextCover);
            if(i == curCover){
                if(curCover != nums.size() - 1){
                    res++;
                    curCover = nextCover;
                    if(nextCover >= nums.size() - 1){
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
        return res;
    }
};

// 
class Solution {
public:
    int jump(vector<int>& nums) {
        int curCover = 0;
        int nextCover = 0;
        int res = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            nextCover = max(i + nums[i], nextCover);
            if(i == curCover){
                res++;
                curCover = nextCover;
            }
        }
        return res;
    }
};