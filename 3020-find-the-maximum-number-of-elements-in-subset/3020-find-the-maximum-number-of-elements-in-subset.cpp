class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> freq;

        for(int x : nums) freq[x]++;

        unordered_set<int> st(nums.begin(), nums.end());

        int ans = 1;

        // handle 1 separately
        if(freq.count(1))
            ans = freq[1] % 2 ? freq[1] : freq[1] - 1;

        for(int x : st){
            if(x == 1) continue;

            long long cur = x;
            int len = 0;

            while(freq[cur] >= 2){
                len += 2;
                cur = cur * cur;
            }

            if(freq[cur] >= 1)
                len += 1;
            else
                len -= 1;

            ans = max(ans, len);
        }

        return ans;
    }
};