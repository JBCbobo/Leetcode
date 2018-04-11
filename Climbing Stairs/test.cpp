class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,1);
        int i;
        for(i=0;i<dp.size();i++)
        {
            if(i>1) dp[i] = dp[i-2] + dp[i-1]; 
        }
        return dp[i-1];
    }
}; 