// 2022.04.08
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = 0;
        for(auto num : nums){
            ab ^= num;
        }
        int i;
        for(i = 0; i < 32; i++){
            if(ab & 1 << i){
                break;
            }
        }
        int resa = 0;
        int resb = 0;
        for(auto num : nums){
            if(num & 1 << i){
                resa ^= num;
            }
            else{
                resb ^= num;
            }
        }
        return {resa, resb};
    }
};