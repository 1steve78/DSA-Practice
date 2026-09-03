class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        
        int mn = *min_element(nums1.begin(),nums1.end());

        bool hasOdd = false;
        for(int x : nums1 ){
            if(x % 2 == 1) {
                hasOdd = true;
                break;
            }
        }

        if(mn % 2 == 0 && hasOdd) return false;

        return true;
    }
};