class Solution {
public:
    int atMost(vector<int> nums, int goal){
        int l = 0 , n = nums.size();
        int cnt = 0 , sum=0;
        for(int r =0 ; r< n ;r++){
            sum += nums[r];
            while(sum>goal){
                sum -= nums[l++];
            }

            cnt += r-l+1;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0 ; i<n ; i++){
            nums[i] %= 2;
        }

        return atMost(nums,k) - atMost(nums,k-1);
    }
};