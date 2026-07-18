#include <array>
const int NUM_LETTERS = 26;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        std::array<int, NUM_LETTERS> scores = {0};
        for(int i = 0; i < s.length(); i++) {
            scores[int(s[i]) - 'a'] += 1;
            scores[int(t[i]) - 'a'] -= 1;
        }
        for(int i = 0; i < NUM_LETTERS; i++) {
            if(scores[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
