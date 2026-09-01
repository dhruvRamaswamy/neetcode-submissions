class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int back = numbers.size() - 1;
        int front = 0;
        // Back will never be front in this example, right? because there is a valid solution
        vector<int> ret(2);
        while(numbers[front] + numbers[back] != target) {
            int val = numbers[front] + numbers[back];
            if(target > val) {
                
                front++;
                // std::cout << "Front: " + std::to_string(front);
            }
            else {
                back--;
                // std::cout << "Back: " + std::to_string(back);
            }
            
        }
        ret[0] = front + 1;
        ret[1] = back + 1;
        return ret;
    }
};
