class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;
        int leftMax = 0;
        int rightMax = 0;
        int water = 0;
        while (left < right) {
            if(height[right] > height[left]){
                leftMax = max(leftMax, height[left]);
                // printf("leftMax: %d\n", leftMax);
                water += leftMax - height[left];
                left++;
            }
            else {
                rightMax = max(rightMax, height[right]);
                // printf("rightMax: %d\n", rightMax);
                water += rightMax - height[right];
                right--;
            }
            // printf("water: %d, left: %d, right: %d\n", water, left, right);
        }
        return water;
    }
};
