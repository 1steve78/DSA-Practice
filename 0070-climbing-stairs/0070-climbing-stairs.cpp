class Solution {
public:
    int helper(int x ,vector<int> & dp){
        if(x==0 || x==1 ) return 1;
        if(dp[x]!=-1) return dp[x];
        return dp[x]=helper(x-1,dp)+helper(x-2,dp); 
    }
    int climbStairs(int n) {
        vector<int> dp (n+1,-1);
        return helper(n ,dp);
    }
};