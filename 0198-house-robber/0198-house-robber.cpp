class Solution {
public:
    int helper(int i , int &n ,vector<int> & nums ,vector<int> & dp ){
        if(i>=n) return 0 ;
        if(dp[i]!=-1) return dp[i];

        int ans1 = nums[i]+helper(i+2,n,nums,dp);
        int ans2 =helper(i+1,n,nums,dp);
        return dp[i]=max(ans1,ans2); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n+1,-1);
        return helper(0,n,nums,dp);
    }
};