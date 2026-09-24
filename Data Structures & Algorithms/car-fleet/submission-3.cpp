class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // Do this now...
        int n = position.size();
        vector<pair<int, int>> cars(n);

        // Fil the cars array
        for (int i = 0; i < n; i++){
            // Position needs to go here
            cars[i] = {position[i], speed[i]};
        }
        // now sort it

        //posAndSpeed()
        // comback to thisg
        // add the option greater?
        sort(cars.begin(), cars.end(), greater<pair<int, int>>());


        int numFleets = 1;
        double mostTime = (0.0 + target - cars[0].first) / cars[0].second;;
        // printf("mostTime first car: %lf\n", mostTime);
        // Work backwards, but remember its sorted in descending order
        for(int i = 1; i < n; i++) {
            // calcuate when it is going to reach destination
            int position = cars[i].first;
            int speed = cars[i].second;
            double carTime = (0.0 + target - position) / speed;

            
            if(carTime > mostTime) {
                mostTime = carTime;
                numFleets++;
            }
            else {
                
            }
            // printf("Position for car: %d, carTime for car %d: %lf, numFleets: %d\n", position, i, carTime, numFleets);

        }

        return numFleets;

        
    }
};
