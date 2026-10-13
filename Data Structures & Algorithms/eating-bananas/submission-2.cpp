class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // The trick is you aren't searching over possible speeds (k) for the first one that works
        int lo = 1; // This is the slowest speed (1 bana per pile per hour)
        //remember to de-reference it, it is an iterator
        int hi = *max_element(piles.begin(), piles.end());

        while(lo < hi) {
            //
            int mid = lo + (hi - lo) / 2;
            printf("Speed to try: %d\n", mid);
            if(canEatInTime(mid, h, piles)) {
                // We can eat in time 
                // so there is a slower speed out there
                hi = mid;
            }
            else {
                // we cant eat in time
                // There is a faster speed out there
                lo = mid + 1;
            }
        }
        return lo;

        // Another trick with binary

    }
    int canEatInTime(int eatingSpeed, int target, vector<int>& piles) {
        int hours = 0;
        for (int b : piles){
            hours += (b + eatingSpeed - 1) / eatingSpeed;
        }
        // idk if it should be < or <= yet
        printf("Hours to eat piles at %d rate: %d\n", eatingSpeed, hours);
        return hours <= target;
    }
};
