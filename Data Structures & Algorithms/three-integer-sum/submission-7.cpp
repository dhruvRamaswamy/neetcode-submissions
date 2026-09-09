class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // On(3) would be pretty easy
        // But O(n^2) is the challenge
        // So turns out you have to sort the algorithm before hand...
        vector<vector<int>> ret;
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        for(const int k : nums) {
            cout << std::to_string(k) + " ";
        }
        // Come back to this, I think I got it
        for(int i = 0; i < n - 2; i++) {
            // micro opimization is that if the smallest number is greater than 0, it can't ever go past that
            if(nums[i] > 0){
                break;
            }
            // Don't want duplicates
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int back = nums.size() - 1;
            int front = i + 1;
            int target = -nums[i];
            std::unordered_set<int> s;
            while(back > front) {
                int val = nums[front] + nums[back];
                // cout << "\nVal: " + std::to_string(val) + " ";
                // cout << "target: " + std::to_string(target) + " ";
                // cout << "back: " + std::to_string(back) + " ";
                // cout << "front: " + std::to_string(front) + " ";
                if(target > val) {
                
                    front++;
                    // std::cout << "Front: " + std::to_string(front);
                }
                else if (target < val) {
                    back--;
                    // std::cout << "Back: " + std::to_string(back);
                } 
                else {
                    // Okay, now we know that we have it
                    //cout << "\nfound one!";
                    // Using a hashmap holds up, but there is a better way...
                    
                    ret.push_back({nums[i], nums[front], nums[back]});
                    while (front < back && nums[front] == nums[front + 1]) front++;
                    while (front < back && nums[front] == nums[back - 1]) back--;
                    front++;
                    back--;
                }
            
            }



        }
        return ret;
    }
    
};
/*
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // Back will never be front in this example, right? because there is a valid solution
        vector<int> ret(2);
        
        ret[0] = front + 1;
        ret[1] = back + 1;
        return ret;
    }
};
*/