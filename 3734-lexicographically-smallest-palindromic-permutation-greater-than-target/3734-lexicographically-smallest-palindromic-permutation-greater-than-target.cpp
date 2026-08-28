class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int m = n / 2;

        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
        }

        // Check whether s can form a palindrome.
        int odd = 0;
        int middle = -1;

        for (int c = 0; c < 26; c++) {
            if (cnt[c] % 2) {
                odd++;
                middle = c;
            }
        }

        if (odd > 1) {
            return "";
        }

        // Counts available for the first half.
        vector<int> half(26);
        for (int c = 0; c < 26; c++) {
            half[c] = cnt[c] / 2;
        }

        string t = target.substr(0, m);

        /*
         * Find the smallest permutation of `half` that is
         * lexicographically greater than t.
         *
         * We first follow t as far as possible.
         */
        string prefix;
        vector<int> rem = half;

        int failPos = m;

        for (int i = 0; i < m; i++) {
            int c = t[i] - 'a';

            if (rem[c] == 0) {
                failPos = i;
                break;
            }

            prefix.push_back(t[i]);
            rem[c]--;
        }

        /*
         * Case 1:
         * We could construct all of t.
         *
         * If the palindrome formed from t is already > target,
         * it is the answer.
         */
        if ((int)prefix.size() == m) {
            string ans = makePalindrome(prefix, middle, n);

            if (ans > target) {
                return ans;
            }

            /*
             * Otherwise the first half is exactly t, so we need
             * the next lexicographically larger permutation.
             */
            failPos = m - 1;
        }

        /*
         * Try to increase a position.
         *
         * If matching failed at position failPos, that position
         * must also be considered.
         *
         * Then we move left, because changing the rightmost possible
         * position gives the smallest larger permutation.
         */
        for (int pos = failPos; pos >= 0; pos--) {
            vector<int> available = half;

            // Use the prefix before `pos`.
            for (int i = 0; i < pos; i++) {
                available[t[i] - 'a']--;
            }

            int start = t[pos] - 'a' + 1;

            // Find the smallest character greater than t[pos].
            for (int c = start; c < 26; c++) {
                if (available[c] == 0) {
                    continue;
                }

                available[c]--;

                string first = t.substr(0, pos);
                first.push_back(char('a' + c));

                // Fill the rest with the smallest characters.
                for (int x = 0; x < 26; x++) {
                    first.append(available[x], char('a' + x));
                }

                if ((int)first.size() != m) {
                    continue;
                }

                string ans = makePalindrome(first, middle, n);

                if (ans > target) {
                    return ans;
                }
            }
        }

        return "";
    }

private:
    string makePalindrome(const string& first, int middle, int n) {
        string ans = first;

        if (n % 2) {
            ans.push_back(char('a' + middle));
        }

        for (int i = (int)first.size() - 1; i >= 0; i--) {
            ans.push_back(first[i]);
        }

        return ans;
    }
};