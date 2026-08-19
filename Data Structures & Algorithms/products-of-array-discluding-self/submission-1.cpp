class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1,2,4,6]
        // [48,24,12,8]
        // So the super simple solution (of adding all products then dividing seems pretty easy... but it aint)
        // You can't use division, and even then all the info gets "quashed" when there is a zero, so you have to keep two sums (one is obviously zero and the other one isn't)
        // So now how do we do it without division?
        // Two pass approach: first don't account for zeros. 
        // If you can get the product of the left and the product of the right, then you can get the product of the current 


        vector<int> retNums(nums.size());
        vector<int> postFixProduct(nums.size());
        vector<int> preFixProduct(nums.size());
        
        int product = 1;
        for(int i = 0; i < preFixProduct.size(); i++) {
            product *= nums[i];
            preFixProduct[i] = product;
        }


        product = 1;

        for(int i = nums.size() - 1; i >= 0; i--) {
            product *= nums[i];
            postFixProduct[i] = product;
        }
        


        for(int i = 0; i < nums.size(); i++) {
            if(i == 0){
                retNums[i] = postFixProduct[i + 1];
            }
            else if (i == nums.size() - 1) {
                retNums[i] = preFixProduct[i - 1];
            }
            else {
                retNums[i] = postFixProduct[i + 1] * preFixProduct[i - 1];
            }
        }

        return retNums;
    }
};
