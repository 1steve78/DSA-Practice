class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0;

        for (int i = 0; i < k; i++)
            lsum += cardPoints[i];

        int r = n - 1;
        int maxSum = lsum;

        for (int l = k - 1; l >= 0; l--) {
            lsum -= cardPoints[l];
            rsum += cardPoints[r--];

            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};