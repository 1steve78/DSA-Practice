class Solution {
public:
    bool sumGame(string num) {
        int leftQ = 0 ,leftSum =0;
        int rightQ = 0 , rightSum = 0;

        int n = num.size();
        for(int i = 0 ; i< n/2 ;i++){
            if(num[i]=='?') leftQ++;
            else leftSum+=(num[i]-'0');

            if(num[n-i-1]=='?') rightQ++;
            else rightSum+=(num[n-i-1]-'0');
        }
        int qDiff = leftQ - rightQ;
        int sumDiff = leftSum - rightSum;

        if((leftQ+rightQ)%2){
            return true;
        }

        return  sumDiff * 2 != -9 * qDiff;
    }
};