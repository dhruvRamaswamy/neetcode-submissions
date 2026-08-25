class Solution {
public:
    bool isValid(string s) {
        // We have to remember syntax of a stack:
        // You might think to intialize it but that actually allocates memory on the hea
        // And then you have to deal with that
        // I was thinking of using a hashet for this but it is so tiny it doesn't matter
        // Top, pop, push are valid methods
        if(s.size() % 2 != 0){
            return false;
        }
        std::stack<char> stackOfParens;
        //.at()
        for(int i = 0; i < s.size(); i++){
            char c = s.at(i);
            if(c == '{' || c == '[' || c == '(') {
                stackOfParens.push(c);
            }
            else {
                // So we know it isn't a starting paren, so it must be an ending one.
                // Pop doesn't return (like a lot of weird methods)
                if(stackOfParens.size() == 0){
                    return false;
                }
                char pc = stackOfParens.top();
                
                if (!((pc == '{' && c == '}') || (pc == '[' && c == ']') || (pc == '(' && c == ')'))) {
                    return false;
                }
                stackOfParens.pop();
            }
        }
        return stackOfParens.size() == 0;
    }
};
