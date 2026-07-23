class Solution {
public:

    int get_msb_index(unsigned int n) {
        if (n == 0) return -1;
        int index = 0;
        while (n >>= 1) { // Shift right until no bits remain
            index++;
        }
        return index;
    }

    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n<=2) return n;

        int cnt =0;
        int limit = (1 << (get_msb_index(n) + 1)) - 1;
        for(int i = 0 ; i<= limit; i++ ){
            cnt++;
        }
        return cnt;
    }
};