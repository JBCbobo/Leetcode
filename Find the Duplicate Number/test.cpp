class Solution1 {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,bool> dup;
        for(int i=0;i<nums.size();i++)
        {
            if(dup[nums[i]]==true)
            {
                return nums[i];
            }
            dup[nums[i]] = true;
        }      
    }
};


class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int nums_size = nums.size();
        
        for (int i = 0; i < nums_size; i++)
        {
            if (nums[abs(nums[i])]< 0) return abs(nums[i]);
            
            nums[abs(nums[i])] = -nums[abs(nums[i])];
        }
    }
};