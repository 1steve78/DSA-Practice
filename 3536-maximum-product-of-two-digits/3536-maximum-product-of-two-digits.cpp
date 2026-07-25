class Solution {
public:
    int maxProduct(int n) {
        string s = to_string(n);

        int first = -1, second = -1;

        for (char c : s) {
            int d = c - '0';
            if (d > first) {
                second = first;
                first = d;
            } else if (d > second) {
                second = d;
            }
        }

        return first * second;
    }
};