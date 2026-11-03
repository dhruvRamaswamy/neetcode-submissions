class Solution {
public:
    int characterReplacement(string s, int k) {
        int freqs[26] = {0};
        int l = 0, maxFreq = 0, best = 0;
        for(int i = 0; i < s.size(); i++) {
            // Key insight max freq can be updated, and stale values are fine
            maxFreq = max(maxFreq, ++freqs[s[i] - 'A']);

            // If the window needs more than k replacements
            while ((i - l + 1) - maxFreq > k) {
                --freqs[s[l] - 'A'];
                l++;
            }

            // Now check valid window
            best = max(best, i - l + 1);
        }
        return best;
    }
};
