class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        
        int n = nums.size();
        unordered_map<int, int> freq;
        int l = 0, r = 0;

        int maxLen = 0;

        while (r < n) {

            if (freq.find(nums[r]) != freq.end()) {

                if (freq[nums[r]] >= k) {

                    while (nums[l] != nums[r]) {
                        freq[nums[l]]--;
                        l++;
                    }

                    // Remove the previous occurrence of nums[r]
                    freq[nums[r]]--;
                    l++;
                }

                // Add current nums[r]
                freq[nums[r]]++;
            }
            else {
                freq[nums[r]] = 1;
            }

            int len = r - l + 1;
            maxLen = max(maxLen, len);

            r++;
        }

        return maxLen;
    }
};