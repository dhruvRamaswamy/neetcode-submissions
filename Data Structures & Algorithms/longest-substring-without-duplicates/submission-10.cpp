class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // A better solution
        unordered_map<char, int> charIndexMap;
        int maxLength = 0;
        int begin = 0;
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
             // THe idea is you the character is seen and is within current window
             // You say where it is....
            if(charIndexMap.contains(c) && charIndexMap[c] >= begin) {
                // The key is the previous char.... 
                begin = charIndexMap[c] + 1;
                // printf("Doesn't contain %c", c);
            }

            charIndexMap[c] = i;

            // Calculate max Length; --> later use max function()
            if (maxLength < i - begin + 1) {
                maxLength = i - begin + 1;
            }
        }

        return maxLength;
    }
};
