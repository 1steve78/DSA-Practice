class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                auto [a1, b1] = pair<int,int>{intervals[i][0], intervals[i][1]};
                auto [a2, b2] = pair<int,int>{intervals[j][0], intervals[j][1]};

                if(a1 >= a2 && b1 <= b2 &&
                   (a1 > a2 || b1 < b2)) {
                    cnt++;
                    break;
                }
            }
        }

        return n - cnt;
    }
};