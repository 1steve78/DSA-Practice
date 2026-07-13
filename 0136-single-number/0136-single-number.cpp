class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        
        int ans=0;
        unordered_map<int,int> freq;
        for(int i = 0 ; i< nums.size(); i++){
            freq[nums[i]]++;
        }

        for(auto & a : freq){
            if(a.second==1){
                ans = a.first;
                break;
            }
        }
        return ans;
    }
};