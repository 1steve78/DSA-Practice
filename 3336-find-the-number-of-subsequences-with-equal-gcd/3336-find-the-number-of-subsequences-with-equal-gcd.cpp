class Solution {
public:
    static const int MOD = 1e9 + 7;
    

    int solve(int i , vector<int> & nums ,int g1 ,int g2 , vector<vector<vector<int>>> & dp){
        if(i==nums.size()) return (g1==g2 && g1!=0);
         
        if(dp[i][g1][g2]!=-1) return dp[i][g1][g2];

        long long ans =0;

        ans += solve(i+1,nums,g1,g2,dp);

        ans += solve(i+1,nums,gcd(g1,nums[i]),g2,dp);

        ans += solve(i+1,nums,g1,gcd(nums[i],g2),dp);

        return dp[i][g1][g2] = ans %MOD;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        vector<vector<vector<int>>> dp(n,vector<vector<int>> (201, vector<int>(201,-1)));
        return solve(0,nums,0,0,dp);
    }
};