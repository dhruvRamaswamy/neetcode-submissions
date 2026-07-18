class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //The simple way: not very efficient, but something
        vector<int> tupleValue(2);
        for(auto i = 0; i < nums.size(); i++) {
            for(auto j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) {
                    return {static_cast<int>(i), static_cast<int>(j)};
                }
            }
        }
        return {};
    }
};
