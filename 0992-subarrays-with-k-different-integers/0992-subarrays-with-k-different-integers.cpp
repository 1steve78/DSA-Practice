class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int l = 0;
        int ans = 0;
        int types = 0;

        unordered_map<int, int> mp;

        for (int r = 0; r < nums.size(); r++) {

            if (mp[nums[r]] == 0) {
                types++;
            }

            mp[nums[r]]++;

            while (types > k) {
                mp[nums[l]]--;

                if (mp[nums[l]] == 0) {
                    types--;
                }

                l++;
            }
            ans += r - l + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};