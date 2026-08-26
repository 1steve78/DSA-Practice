class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int l = 0 , n = s.size();
        int ones = 0;
        string ans = "";
        int minLen = INT_MAX; 
        for(int r = 0 ; r< n ;r++){
            if(s[r] == '1') ones++;

            while(ones>k){
                if(s[l] == '1') ones--;
                l++;
            }

            if(ones == k){

                while(s[l]=='0') l++;

                int len = r - l+1;

                if(len < minLen){
                    minLen = len;
                    ans = s.substr(l,len);
                }
                else if(len == minLen){
                    string temp = s.substr(l,len);
                    if(temp<ans) ans = temp;
                }
                

            }
        
        }
        return ans;
    }
};