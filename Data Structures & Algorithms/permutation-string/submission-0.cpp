class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqA(26, 0), freqB(26, 0);
        int s1s = s1.size();
        int s2s = s2.size();

        if(s1s > s2s) {
            return false;
        }

        for(int i = 0; i < s1s; i++) {
            freqA[s1[i] - 'a']++;
            freqB[s2[i] - 'a']++;
        }

        if (freqA == freqB) {
            return true;
        }
        // Add 1.. but i don't think s0
        for(int i = s1s; i < s2s; i++) {
            freqB[s2[i] - 'a']++;
            freqB[s2[i - s1s] - 'a']--;
            
            if(freqA == freqB) {
                printf("Sliding: %d", i);
                return true;
            }
        }

        return false;
        
    }
};
