class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hashmap (number to number), initializing everyrthing to zero
        std::unordered_map<int, int> numberFrequency;
        // btw you can't use array here because the size isn't known at compile time
        //Allocates correct number of elements
        vector<vector<int>> frequencyChart(nums.size() + 1)
        ;

        vector<int> result;
        // Populate array
        for(const int num : nums) {
            numberFrequency[num]++;
        }

        // allocates memory capacity but doesn't actuallly resize vector
        // frequencyChart.reserve(nums.size());

        for(const auto&[number, frequency] : numberFrequency) {
            // auto instantiates vector if it isn't there
            frequencyChart[frequency].push_back(number);
        }
        
        int index = nums.size();
        while(k > 0) {
            //get index
            while(frequencyChart[index].empty()) {
                index--;
            }
            int l = frequencyChart[index].back();
            result.push_back(l);
            frequencyChart[index].pop_back();
            k--;
        }

        return result;
        
    }
};
