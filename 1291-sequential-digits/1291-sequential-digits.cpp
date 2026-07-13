class Solution {
public:
    int  tens(int n ){
        int cnt = 0 ;
        while(n>0){
            cnt++;
            n /=10;
            
        }
        return cnt;
    }
    vector<int> sequentialDigits(int low, int high) {
        int lowtens = tens(low) , hightens = tens(high);
        vector<int>  ans;
        for(int i = lowtens ; i<= hightens; i++){
            for(int j = 1; j<=10-i;j++){
                int seq=0;
                for(int k = j; k< i+j ; k++){
                    seq = seq*10 + k;
                }
                if(low<=seq && seq<=high) ans.push_back(seq);
            }
               
        }
        return ans;
    }
};