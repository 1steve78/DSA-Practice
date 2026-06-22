class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int cntb = 0,cnta=0,cntl=0,cnto=0,cntn=0;
        for(char c: text){
            if(c=='a')cnta++;
            else if(c=='b')cntb++;
            else if(c=='l')cntl++;
            else if(c=='o') cnto++;
            else if(c=='n')cntn++;

        }
        
        return min({cntb,cnta,cntl/2,cnto/2,cntn});
    }
};