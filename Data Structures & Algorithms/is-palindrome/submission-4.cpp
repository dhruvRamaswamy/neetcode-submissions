class Solution {
public:
    bool isPalindrome(string s) {
        // So turns out this can have a lot of bugs
        int front = 0;
        int back = s.size() - 1;
        while(front < back) {
            
            while(!std::isalnum(s[front])){
                front++;
            }
            while(!std::isalnum(s[back])){
                back--;
            }
            if(front >= back) {
                return true;
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
