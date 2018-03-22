class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int depth = 1,max_depth=1;
        if(nums.empty()) return 0;
        for(int i=0;i<nums.size()-1;i++)
        {
            nums[i+1]>nums[i]? depth++:depth = 1;
            if(depth>max_depth) max_depth=depth;                    
        }
        
        return max_depth;
        
    }
};