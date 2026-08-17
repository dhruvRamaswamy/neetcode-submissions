class Solution {
public:

    string encode(vector<string>& strs) {
        string retString = "";
        for (const string& str : strs) {
            // String bug (weird pointer arithmetic), must do toString
            retString += std::to_string(str.size()) + "#" + str;
        }
        std::cout << retString;
        return retString;
    }

    vector<string> decode(string s) {
        //Get number of strings there are
        
        vector<string> ret;
        size_t i = 0;
        while(i < s.size()) {
            size_t delimiterPosition = s.find("#", i);
            std::cout << delimiterPosition;
            // Get the number
            int numChars = std::stoi(s.substr(i, delimiterPosition - i));
            string word = s.substr(delimiterPosition + 1, numChars);
            ret.push_back(word);
            // Push it beyond delimiter plus the length of the word. 
            // This is to acount for the top condition
            // Also we don't have to keep a running track of the delimiter
            i = delimiterPosition + 1 + numChars;

        }
        
        
        return ret;
    }
};
