class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n =s.size();

        unordered_map<char,int> hash;

        int l = 0 ;
        int maxLen = 0;
        for(int r = 0 ; r < n ; r++){
            if(hash.find(s[r]) != hash.end()){
                if(hash[s[r]]>=l){
                    l = hash[s[r]]+1;
                }
            }
            hash[s[r]] = r;
            int len = r -l+1;
            maxLen = max(maxLen,len);
        }
        return maxLen;
    }
};