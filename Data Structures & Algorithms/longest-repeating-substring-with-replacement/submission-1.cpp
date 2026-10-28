class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);   // count of each letter in the current window
        int left = 0;
        int maxFreq = 0;           // highest count of any single letter in a window
        int longest = 0;

        for (int right = 0; right < s.size(); right++) {
            // Add the new character to the window
            int idx = s[right] - 'A';
            freq[idx]++;
            maxFreq = max(maxFreq, freq[idx]);

            // Characters we'd need to replace = window size - most frequent count
            int windowSize = right - left + 1;
            int replacementsNeeded = windowSize - maxFreq;

            // Too many replacements needed, so shrink from the left
            if (replacementsNeeded > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            // Update the best answer
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
