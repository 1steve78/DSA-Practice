class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0 ;

        int maxLen = 0;
        unordered_map<int,int> freq;
        int types = 0;
        for(int r  = 0 ; r< n ; r++){
            freq[fruits[r]]++;
            if (freq[fruits[r]] == 1)
                types++;
            

            while(types>2){
                freq[fruits[l]]--;
                
                if(freq[fruits[l]]==0){
                    types--;
                }
                l++;
            }
            int len =r -l +1;
            maxLen = max(maxLen,len);
        }
        return maxLen;

        
    }
};