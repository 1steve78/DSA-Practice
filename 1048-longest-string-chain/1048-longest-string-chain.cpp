class Solution {
public:

    bool compare(string &s, string &t){

        if(s.size() != t.size() + 1)
            return false;

        int i = 0, j = 0;

        while(i < s.size()){

            if(j < t.size() && s[i] == t[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }

        return j == t.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
            [](string &a, string &b){
                return a.size() < b.size();
            });
        vector<int> dp(n,1);
        int maxi = 1;
        for(int i = 0 ; i <  n ; i++){
            for(int j = 0 ; j< i ; j++){
                if(compare(words[i],words[j]) && dp[i]<dp[j] +1){
                    dp[i] = dp[j]+1;
                }
            }
            maxi = max(maxi,dp[i]);
        }
        return maxi;
    }
};