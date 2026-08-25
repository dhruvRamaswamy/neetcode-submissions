class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> operands;
        // I don't know if we need this yet
        std::stack<string> operators;

        for(const string& str: tokens) {
            if(str == "+" || str == "*" || str == "-" || str == "/"){
                // is an operator
                int operand2 = operands.top();
                operands.pop();
                int operand1 = operands.top();
                operands.pop();
                int put;
                if(str == "+") {
                    put = operand1 + operand2;
                }
                else if (str == "-") {
                    put = operand1 - operand2;
                }
                else if (str == "*") {
                    put = operand1 * operand2;
                }
                else  {
                    put = operand1 / operand2;
                }
                operands.push(put);
            }
            else {
                operands.push(std::stoi(str));
            }
        }
        return operands.top();

    }
};
