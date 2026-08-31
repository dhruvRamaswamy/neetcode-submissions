class Solution {
public:
    bool isPalindrome(string s) {
        int front = 0;
        int back = s.size() - 1;
        for(int k = 0; k < s.size() / 2; k++){
            
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
