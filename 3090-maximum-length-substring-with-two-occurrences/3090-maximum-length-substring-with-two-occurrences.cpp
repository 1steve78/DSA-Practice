class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26,0);
        int n =  s.size();
        int l = 0, maxLen=0;

        for(int r = 0 ; r< n ; r++){
            freq[s[r]-'a']++;
            while(freq[s[r]-'a']>2){
                freq[s[l]-'a']--;
                l++;
            }
            int len = r-l+1;
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};