class MinStack {
public:
    std::stack<int> internalS;
    std::stack<int> minValues;
    int currTop;
    MinStack() {
        // Ok to use a stack
        internalS = std::stack<int>();
        minValues = std::stack<int>();
    }
    
    void push(int val) {
        internalS.push(val);
        if(minValues.size() == 0 || val <= minValues.top()) {
            // push it to the stack
            minValues.push(val);
        }
        std::cout << minValues.top();
    }
    
    void pop() {
        int temp = internalS.top();
        internalS.pop();
        if(temp == minValues.top()){
            minValues.pop();
        }
    }
    
    int top() {
        return internalS.top();
    }
    
    int getMin() {
        return minValues.top();
    }
};
