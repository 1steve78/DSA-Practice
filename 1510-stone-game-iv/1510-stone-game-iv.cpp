class Solution {
public:
    vector<int> memo;
    int solve(int n){
        if(n==0) return false;

        if(memo[n]!=-1) return memo[n];

        for(int k = 1 ; k*k<=n ; k++){
            if(!solve(n-k*k)) return memo[n]=1;
        }
        return memo[n]=0;
    }
    bool winnerSquareGame(int n) {
        memo.resize(n+1,-1);
        return solve(n);
    }
};