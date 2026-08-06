class Solution {
public:
    int prod(int n ){
        int product = 1;
        while(n>0){
            int rem = n % 10;
            product *= rem;
            n /= 10;
        }
        return product;
    }
    int smallestNumber(int n, int t) {
        int ans= n;
        int i = n ;
        while(i<1e9){
            if(prod(i)%t ==0 ){
                ans = i;
                break;
            }
            i++;
        }

       
        return  ans;
    }
};