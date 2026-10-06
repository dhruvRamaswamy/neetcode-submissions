class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;
        int max = 0;
        while(right > left){
            // calculate current val
            // printf("Right %d, Left %d\n", right, left);
            int pot = calculateArea(right, left, heights);
            // Then calcuate which way we should move
            if(pot > max){
                max = pot;
            }
            // int leftMove = calculateArea(right, left + 1, heights);
            // int rightMove = calculateArea(right - 1, left, heights);
            if(heights[right] > heights[left]){
                left++;
            }
            else {
                right--;
            }
            
        }
        return max;

    }
    int calculateArea(int right, int left, vector<int> &heights) {
        return (right - left) * std::min(heights[right], heights[left]);
    }
};
