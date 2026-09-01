class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        //Brute force
        // REMEMBER THIS
        int n = temperatures.size();
        std::stack<int> mts;
        vector<int> retDays(n, 0); 
        // I was wondering how do you keep track of the indexes... but it turns out you can just store the index...
        // Decreasing monotonic stack
        for(int i = 0; i < n; i++) {
            int val = temperatures[i];
            while(mts.size() != 0 && val > temperatures[mts.top()]) {
                int num = mts.top();
                mts.pop();
                retDays[num] = i - num; 
            }
            mts.push(i);
        }

        return retDays;
    }
};
