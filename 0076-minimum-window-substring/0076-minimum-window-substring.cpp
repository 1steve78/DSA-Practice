class Solution {
public:
    string minWindow(string s, string t) {
        int l= 0  , n = s.size();
        int minLen = 1e9;
        int sIdx = -1 ,cnt =0;

        unordered_map<char,int> freq;

        for(char c : t) freq[c]++;

        for(int r =0 ; r< n ;r++){
            if(freq[s[r]]>0) cnt++;
            freq[s[r]]--;

            while(cnt == t.size()){

                if(r-l+1<minLen){
                    minLen = r-l+1;
                    sIdx = l;
                }

                freq[s[l]]++;

                if(freq[s[l]]>0) cnt--;
                l++;
            }

        }

        if (sIdx == -1) return  "";
        return s.substr(sIdx,minLen);
    }
};