class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {

        unordered_set<int> s(nums.begin(), nums.end());

        vector<bool> xy(2048, false);

        for (int x : s)
            for (int y : s)
                xy[x ^ y] = true;

        vector<bool> ans(2048, false);

        for (int z : s)
            for (int i = 0; i < 2048; i++)
                if (xy[i])
                    ans[i ^ z] = true;

        int cnt = 0;
        for (bool x : ans)
            cnt += x;

        return cnt;
    }
};