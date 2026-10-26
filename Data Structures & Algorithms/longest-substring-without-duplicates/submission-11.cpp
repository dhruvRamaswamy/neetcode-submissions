class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // I think you have to use a hashmap
        // This is s[i], i
        int last[256];

        fill(begin(last), end(last), -1);

        int start = 0; 
        int best = 0;

        for(int i = 0; i < s.size(); i++) {
            unsigned char c = s[i];

            if(last[c] >= start) {
                start = last[c] + 1;
            }
            last[c] = i;
            //fence post
            best = max(best, i - start + 1);
        }

        return best;
    }
};
