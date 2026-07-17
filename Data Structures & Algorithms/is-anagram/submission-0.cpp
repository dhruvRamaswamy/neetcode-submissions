#include <array>
const int NUM_LETTERS = 26;
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        std::array<int, NUM_LETTERS> scores1 = {0};
        std::array<int, NUM_LETTERS> scores2 = {0};
        createProfile(scores1, s);
        createProfile(scores2, t);
        return isEquivalent(scores1, scores2);


    }

    void createProfile(std::array<int, NUM_LETTERS>& scores, string s) {
        for(int i = 0; i < s.length(); i++) {
            scores[int(s[i]) - 97] += 1;
        }
    }

    bool isEquivalent(std::array<int, NUM_LETTERS> scores1, std::array<int, NUM_LETTERS> scores2) {
        for(int i = 0; i < NUM_LETTERS; i++) {
            if(scores1[i] != scores2[i]) {
                return false;
            }
        }
        return true;
    }
};
