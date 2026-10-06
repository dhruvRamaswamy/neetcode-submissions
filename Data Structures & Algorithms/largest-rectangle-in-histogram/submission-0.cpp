class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Start from scratch
        // increasing monotonic stack
        stack<int> heightsStack;
        // You always wanna push indexes
        int currRecord = 0;
        // First elegant solution:
        // Push 0 at the back of heights so that the heights are cleared
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++){
            if(i == 0){
                // Pushing indexes
                heightsStack.push(i);
                currRecord = heights[i];
                continue;
            }
            // printf("We are on iteration (index): %d, value: %d \n", i, heights[i]);
            while (heightsStack.size() != 0 && heights[heightsStack.top()] > heights[i]) {
                int height = heights[heightsStack.top()];
                heightsStack.pop();
                int width = heightsStack.empty() ? i : i - heightsStack.top() - 1;
                int potVal = height * width;
                if(potVal > currRecord){
                    currRecord = potVal;
                }
            }
            heightsStack.push(i);
            
        }
        return currRecord;
    }
};
