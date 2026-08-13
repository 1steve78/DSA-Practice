class Solution {
public:
    long long hoursToEat(vector<int>& piles, int k) {
        long long totalHours = 0;

        for (int pile : piles) {
            totalHours += (pile + k - 1) / k;
        }

        return totalHours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());

        while (l <= r) {
            int mid = l + (r - l) / 2;

            long long hours = hoursToEat(piles, mid);

            if (hours <= h) {
                r = mid - 1;  // try a smaller speed
            } else {
                l = mid + 1;  // need a larger speed
            }
        }

        return l;
    }
};