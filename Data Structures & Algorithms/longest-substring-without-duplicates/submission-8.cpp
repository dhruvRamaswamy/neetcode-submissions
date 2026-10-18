class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // I think you have to use a hashmap
        // This is s[i], i
        unordered_map<int, int> chars;
        int begin = 0;
        int end = 0;
        int maxLength = 0;
        for(int i = 0; i < s.size(); i++){
            int charIndex = static_cast<int>(s[i]);
            if(chars.contains(charIndex)) {
                // Find new beginning
                begin = chars[charIndex] + 1;
                // Remove everything before 
                std::erase_if(chars, [begin](const auto& pair) {
    return begin > pair.second;
});
                chars[charIndex] = i;
                end++;
            }
            else {
                chars[charIndex] = i;
                end++;
            }
            // printf("Begin: %d, End %d\n", begin, end);
            if(end - begin > maxLength) {
                maxLength = end - begin;
            }
        }

        return maxLength;
    }
};
