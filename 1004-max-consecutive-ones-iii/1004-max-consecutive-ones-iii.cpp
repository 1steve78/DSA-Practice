class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int n = nums.size() , l = 0 ;
        int zeroes =0 ;
        int maxLen = 0;

        for(int r = 0 ; r< n ;r++){
            if(nums[r]==0) zeroes++;

            while(zeroes>k){
                if(nums[l]==0) zeroes--;
                l++;
            }

        
            int len = r - l +1;
            maxLen = max(maxLen,len);

            
           
        }
        return maxLen;
    }
};