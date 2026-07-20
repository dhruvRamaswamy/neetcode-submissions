class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //The simple way: not very efficient, but something
        std::unordered_map<int, int> numbers_map;
        // The key is to store the indexes
        // restructure the way you think about hashmap
        for(auto i = 0; i < nums.size(); i++) {
            // Correct complement
            int complement = target - nums[i];

            if (numbers_map.contains(complement)) {
                return {numbers_map[complement], i};
            }
            numbers_map[nums[i]] = i;
        }
        return {};
    }
};
