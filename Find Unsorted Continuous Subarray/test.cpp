class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums_sort = nums;
        
        sort(nums_sort.begin(),nums_sort.end(),less<int>());
		#if 0
        for(int i=0;i<nums_sort.size()-1;i++)
        {
            for(int j=0;j<nums_sort.size()-1-i;j++)
            {
                if(nums_sort[j] > nums_sort[j+1])
                {
                    nums_sort[j] = nums_sort[j]^nums_sort[j+1];
                    nums_sort[j+1] = nums_sort[j]^nums_sort[j+1];
                    nums_sort[j] = nums_sort[j]^nums_sort[j+1];
                }
            }
        }
		#endif
        int start = nums.size(), end = 0;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]!=nums_sort[i])
            {
                if(start > i)  start = i;
                if(end < i)  end = i;
            }
        }
        return start-end==nums.size()?0:end-start+1;
    }
};


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> stack ;
        int left=nums.size();
        int right=0;
        for(int i=0;i<nums.size();i++)
        {
            while(!stack.empty()&&nums[stack.top()]>nums[i])
            {
                left = min(left,stack.top());
                stack.pop();
            }
            stack.push(i);
        }        
        while(!stack.empty() )
            stack.pop();
        
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(!stack.empty()&&nums[stack.top()]<nums[i])
           {
                right =max(right,stack.top());
                stack.pop();
            }
            stack.push(i);
        }
        return right-left>0?right-left+1:0;
    }
        
        
};