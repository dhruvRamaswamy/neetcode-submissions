class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> strings_map;
        for(auto i = 0; i < strs.size(); i++) {
            // Sort not the best thing right now but 
            // get it working first and then use string
            string word = strs[i];
            //This make a copy btw
            string sortedString = word;
            std::sort(sortedString.begin(), sortedString.end());
            // c++ will make a new array if one doesn't exist
            // Where does it live on memory? we will find out
            strings_map[sortedString].push_back(word);
        }
        // RAII???
        vector<vector<string>> stringsRet;
        for(const auto& [key, value] : strings_map) {
            stringsRet.push_back(value);
        }

        return stringsRet;


    }
};
// sort all of the strings. into a new array
// then, make a hashmap string --> array of strings 
