class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int cntZero = 0 ;
        int xorAll = 0;

        for(int x : nums){
            if(x==0) cntZero++;
            xorAll ^= x;
        }
        int ans = 0 ;

        if(cntZero==nums.size()){
            ans =0 ;
        }
        else{
            if(xorAll==0) ans = nums.size() -1;
            else ans = nums.size();
    
        }
        return ans;
    }
};