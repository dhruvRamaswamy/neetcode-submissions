class Solution {
public:
    bool isPalindrome(string s) {
        // So turns out this can have a lot of bugs
        int front = 0;
        int back = s.size() - 1;
        while(front < back) {
            
            // This method ensures that for something like ".,", the while loop  will match front and back to the same indexes and then make a comparison. then after front and back update the while loop will end
            while(front < back && !std::isalnum(s[front])){
                front++;
            }
            while(front < back && !std::isalnum(s[back])){
                back--;
            }

            if(std::tolower(s[front]) != std::tolower(s[back])){
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
};
