class Solution {
public:
#define forn(i, n) for (int i = 0; i < n; i++)
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> temp;
        forn(i, n){
            temp.push_back({arr[i],i});
        }
        sort(temp.begin(),temp.end());

        int r =1;
        vector<int> ans(n);
        forn(i,n){
            if(i<n-1 && temp[i].first==temp[i+1].first){
                ans[temp[i].second]=r;
                continue;
            }
            ans[temp[i].second]=r;
            r++;
        }

        return ans;
    }
};