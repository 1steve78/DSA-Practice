class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int x: nums){
            maxi = max(maxi,x);
            mini = min(mini,x);
        }
        return gcd(maxi,mini);
    }
};