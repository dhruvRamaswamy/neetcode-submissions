class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0;
        int power = 1;
        int carry = 0;
        // I just realized a better way is to use a while loop and divde by two each time and mask it with one
        for (int i = 0; i < 32; i++){
            // This isn't very elegant but it works in the complexity
            // Carry probably has some elegant solution
            // Adjust for the carry bit:

            int bit = (a ^ b) & power;
            int bitA = a & power;
            int bitB = b & power;
            if (carry) {
                bit = bit ^ (1 * power);
            }
            sum = sum | bit;
            
            // Now determine if you should carry next time
            
            // printf("\nBitA %d, BitB %d\n", bitA, bitB);
            if (carry) {
                carry = bitA | bitB;
            }
            else {
                carry = bitA & bitB; 
            }

            // First mistake
            power = power * 2;
            printf("Sum: %d, carry: %d, resBit: %d\n", sum, carry, bit);

        }
        return sum;
    }
};
