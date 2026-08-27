class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        string ans;

        for (int i = 0; i < n; i++) {

            int x = target[i] - 'a';

            // Try to match target[i]
            if (freq[x] > 0) {
                ans += target[i];
                freq[x]--;
                continue;
            }

            // Can't match target[i],
            // so try the smallest character greater than target[i].
            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {

                    ans += char('a' + c);
                    freq[c]--;

                    // Remaining characters should be smallest possible.
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }

            // Can't make current position greater.
            // Backtrack.
            while (!ans.empty()) {

                char last = ans.back();
                ans.pop_back();

                // Put the character back.
                freq[last - 'a']++;

                int pos = ans.size();
                int targetChar = target[pos] - 'a';

                // Try to make this position greater.
                for (int c = targetChar + 1; c < 26; c++) {

                    if (freq[c] > 0) {

                        ans += char('a' + c);
                        freq[c]--;

                        // Add remaining characters in sorted order.
                        for (int j = 0; j < 26; j++) {
                            while (freq[j] > 0) {
                                ans += char('a' + j);
                                freq[j]--;
                            }
                        }

                        return ans;
                    }
                }
            }

            return "";
        }

        // We matched the entire target.
        // Example: s = "ab", target = "ab"
        //
        // We need to backtrack because ans == target,
        // but the answer must be STRICTLY greater.

        while (!ans.empty()) {

            char last = ans.back();
            ans.pop_back();

            // Put the character back.
            freq[last - 'a']++;

            int pos = ans.size();
            int targetChar = target[pos] - 'a';

            // Try the smallest character greater than target[pos].
            for (int c = targetChar + 1; c < 26; c++) {

                if (freq[c] > 0) {

                    ans += char('a' + c);
                    freq[c]--;

                    // Fill the rest with smallest characters.
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};