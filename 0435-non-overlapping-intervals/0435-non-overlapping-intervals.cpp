class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(),comp);

        int i = 1, n = intervals.size();
        int cnt = 1;
        int lastEnd = intervals[0][1];
        while(i<n){
            if(lastEnd<=intervals[i][0]){
                cnt++;
                lastEnd = intervals[i][1];
            }
            i++;
        }
        return n - cnt;
    }
};