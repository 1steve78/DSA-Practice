class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();
        
        int i = 0;
        int ans = 0;
        while(i<n){
            if(nums[i]==1){
                cnt++;
                ans = max(ans,cnt);
            } else {
                cnt = 0;
            }
            i++;
        }
        return ans ;
    }
};