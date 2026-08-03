class Solution {
public:
    vector<int> dp;
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n+3,0);
        
        
        for(int i = n-1; i >= 0 ; i--){
            int take =0 ;
            int ans = INT_MIN;
            for(int k = 1 ; k<=3 && i+k-1<n ; k++){
                take +=stoneValue[i+k-1];
                ans = max(ans,take-dp[i+k]);
            }
            dp[i] = ans;
        }
        
        if (dp[0] > 0)
            return "Alice";
        if (dp[0] < 0)
            return "Bob";

        return "Tie";
    }
};