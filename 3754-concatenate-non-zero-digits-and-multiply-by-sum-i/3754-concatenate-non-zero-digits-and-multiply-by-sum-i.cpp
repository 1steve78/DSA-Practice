class Solution {
public:
    long long sumAndMultiply(int n) {
        int nc = n;
        int sum=0;
        int rev= 0;
        while(nc>0){
            int rem = nc%10;
            if(rem!=0){
                rev = rev*10 +rem;    
                sum+=rem;
            }
            nc=nc/10;
        }
        string s = to_string(rev);
        reverse(s.begin(),s.end());

        int x =stoi(s);

        return 1LL*x*sum;

    }
};