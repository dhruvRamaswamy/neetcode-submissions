class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // This might be a good thing
        unordered_set<int> numsDict(nums.begin(), nums.end());
        int best = 0;
        for(auto num : numsDict) {
            if(numsDict.contains(num - 1)){
                // This isn't the start in a potential list
                continue;
            }
            int len = 1;
            while(numsDict.contains(num + 1)){
                len++;
                num++;
            }
            best = max(best, len);
        }
        return best;
    }
    
};
