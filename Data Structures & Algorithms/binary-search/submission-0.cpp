class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<pair<int, int>> vAndI(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            vAndI[i] = {nums[i], i};
        }
        std::sort(vAndI.begin(), vAndI.end());
        int index;
        int left = 0;
        int right = nums.size() - 1;
        while(right >= left){
            index = left + (right - left) / 2;
            int val = vAndI[index].first;
            if(target > val){
                left = index + 1;
            } 
            else if (target < val){
                right = index - 1;
            }
            else {
                return vAndI[index].second;
            }
        }
        return -1;
    }
};
